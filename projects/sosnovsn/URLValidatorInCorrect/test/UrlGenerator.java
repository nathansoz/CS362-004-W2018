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
        urlGeneration = new ArrayList<ArrayList<Tuple<String, Boolean>>>();
        ArrayList<Tuple<String, Boolean>> protocols = new ArrayList<Tuple<String, Boolean>>();
        urlGeneration.add(protocols);

        urlGeneration.get(protocol).add(new Tuple<String, Boolean>("", false));
        urlGeneration.get(protocol).add(new Tuple<String, Boolean>("http://", true));
        urlGeneration.get(protocol).add(new Tuple<String, Boolean>("https://", true));
        urlGeneration.get(protocol).add(new Tuple<String, Boolean>("ftp://", true));
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

        urlGeneration.add(hosts);
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
