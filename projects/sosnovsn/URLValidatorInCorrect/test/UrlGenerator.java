import com.sun.org.apache.xpath.internal.operations.Bool;
import sun.plugin.javascript.navig.Array;

import java.util.*;

public class UrlGenerator {

    private static final int protocol = 0;

    private ArrayList<ArrayList<Tuple<String, Boolean>>> urlGeneration;

    private Queue<Tuple<String, Boolean>> Urls;

    private ArrayList<Integer> counter;

    private void initProtocols()
    {
        
        ArrayList<Tuple<String, Boolean>> protocols = new ArrayList<Tuple<String, Boolean>>();

        protocols.add(new Tuple<String, Boolean>("", true));
        protocols.add(new Tuple<String, Boolean>("http://", true));
        protocols.add(new Tuple<String, Boolean>("https://", true));
        protocols.add(new Tuple<String, Boolean>("ftp://", true));
        protocols.add(new Tuple<String, Boolean>(":/", false));
        protocols.add(new Tuple<String, Boolean>("3://", false));
        protocols.add(new Tuple<String, Boolean>("42://", false));
        protocols.add(new Tuple<String, Boolean>("42abc://", false));
        protocols.add(new Tuple<String, Boolean>("abc42://", true));

        urlGeneration.add(protocols);
    }

    private void initUsernames()
    {
        ArrayList<Tuple<String, Boolean>> usernames = new ArrayList<Tuple<String, Boolean>>();

        usernames.add(new Tuple<String, Boolean>("", true));
        usernames.add(new Tuple<String, Boolean>("nathan@", true));
        usernames.add(new Tuple<String, Boolean>("nathan:password@", true));

        urlGeneration.add(usernames);


    }

    private void initHosts()
    {
        ArrayList<Tuple<String, Boolean>> hosts = new ArrayList<Tuple<String, Boolean>>();

        hosts.add(new Tuple<String, Boolean>("", false));
        hosts.add(new Tuple<String, Boolean>("google.com", true));
        hosts.add(new Tuple<String, Boolean>("images.google.com", true));
        hosts.add(new Tuple<String, Boolean>("0.0.0.0", true));
        hosts.add(new Tuple<String, Boolean>("987.34.566.755", false));


        urlGeneration.add(hosts);
    }

    private void initPorts()
    {
        ArrayList<Tuple<String, Boolean>> ports = new ArrayList<Tuple<String, Boolean>>();

        ports.add(new Tuple<String, Boolean>("", true));
        ports.add(new Tuple<String, Boolean>(":80", true));
        ports.add(new Tuple<String, Boolean>(":443", true));
        ports.add(new Tuple<String, Boolean>(":897", true));
        ports.add(new Tuple<String, Boolean>(":-2", false));
        ports.add(new Tuple<String, Boolean>(":a", false));

        urlGeneration.add(ports);
    }

    private void initStems()
    {
        ArrayList<Tuple<String, Boolean>> stems = new ArrayList<Tuple<String, Boolean>>();

        stems.add(new Tuple<String, Boolean>("", true));
        stems.add(new Tuple<String, Boolean>("@badstem@", false));
        stems.add(new Tuple<String, Boolean>("/stem", true));
        stems.add(new Tuple<String, Boolean>("/stem/anotherStem", true));
        stems.add(new Tuple<String, Boolean>("/stem/anotherStem/", true));

        urlGeneration.add(stems);
    }

    private void initQueries()
    {
        ArrayList<Tuple<String, Boolean>> queries = new ArrayList<Tuple<String, Boolean>>();

        queries.add(new Tuple<String, Boolean>("", true));
        queries.add(new Tuple<String, Boolean>("?test=true", true));
        queries.add(new Tuple<String, Boolean>("?test=true&myTest=false", true));

        urlGeneration.add(queries);
    }

    private boolean incrementCounter(int position)
    {
        if(counter.get(position) < urlGeneration.get(position).size() - 1)
        {
            counter.set(position, counter.get(position) + 1);
            return true;
        }
        else if(position == counter.size() - 1)
        {
            return false;
        }
        else
        {
            counter.set(position, 0);
            return incrementCounter(position + 1);
        }
    }

    public UrlGenerator()
    {
        counter = new ArrayList<Integer>();
        urlGeneration = new ArrayList<ArrayList<Tuple<String, Boolean>>>();
        Urls = new LinkedList<Tuple<String, Boolean>>();
        
        initProtocols();
        initUsernames();
        initHosts();
        initPorts();
        initStems();
        initQueries();

        BuildUrls();
    }

    public Tuple<String, Boolean> Next()
    {
        return Urls.poll();
    }

    private void BuildUrls()
    {
        int size = 1;

        for(ArrayList<Tuple<String, Boolean>> val : urlGeneration)
        {
            size *= val.size();
            counter.add(0);
        }

        for(int i = 0; i < size; i++)
        {
            Urls.add(BuildUrl());
            incrementCounter(0);
        }

    }

    private Tuple<String, Boolean> BuildUrl()
    {
        StringBuilder builder = new StringBuilder();
        Boolean valid = true;
        for(int i = 0; i < urlGeneration.size(); i++)
        {
            Tuple<String, Boolean> part = urlGeneration.get(i).get(counter.get(i));
            builder.append(part.First);
            valid = valid && part.Second;
        }

        return new Tuple<String, Boolean>(builder.toString(), valid);
    }
}
