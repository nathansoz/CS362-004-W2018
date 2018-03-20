

import junit.framework.TestCase;
import org.junit.Assert;
import org.junit.Test;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }


   public void testYourFirstPartition() {
       // First partition to check that all urls that have an invalid character will be invalid.
       UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       // Invalid Protocol
       try{
           assertTrue(!validator.isValid("42:nathan@google.com:80/stem"));
       }
       catch(Error e)
       {
           System.out.println("ERROR! Unhandled error thrown from url validator!!!");
           Assert.assertTrue(false);
       }
       try{
           // Invalid Hosts
           assertTrue(!validator.isValid("abc42://987.34.566.75:80/stem/anotherstem?"));
       }
       catch(Error e)
       {
           System.out.println("ERROR! Unhandled error thrown from url validator!!!");
           Assert.assertTrue(false);
       }
       try{
           //Invalid Port
           assertTrue(!validator.isValid("https://images.google.com:a"));
       }
       catch(Error e)
       {
           System.out.println("ERROR! Unhandled error thrown from url validator!!!");
           Assert.assertTrue(false);
       }
       try{
           // Invalid Stem
           assertTrue(!validator.isValid("https://images.google.com@badstem@"));
       }
       catch(Error e)
       {
           System.out.println("ERROR! Unhandled error thrown from url validator!!!");
           Assert.assertTrue(false);
       }
   }



   // Second Partician to test that good urls will work.
   public void testYourSecondPartition(){
       UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       try{
           assertTrue(validator.isValid("http://google.com:80/stem"));
       }
       catch(Error e)
       {
           System.out.println("ERROR! Unhandled error thrown from url validator!!!");
           Assert.assertTrue(false);
       }
   }

   /*
        The below is a combination of unit and manual testing. I tend to prefer having several small unit tests that validate
        basic functionality of things that I know should work. This allows for much easier development vs. a monolithic
        test function because if you break something you can quickly isolate the problem due to the test name

        I then implement a larger test function that tests all possible inputs as something to catch edge cases
    */


   public void testBasicValidUrl()
   {
       UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       assertTrue(validator.isValid("http://testurl.com"));
   }

    public void testBasicValidUrlHttps()
    {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

        try
        {
            assertTrue(validator.isValid("https://testurl.com"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }

    public void testBasicValidUrlUncommonProtocol()
    {
        try
        {
            UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
            assertTrue(validator.isValid("vsts://testurl.com"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }

   public void testBasicValidUrlWithStem()
   {
       UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       assertTrue(validator.isValid("http://testurl.com/test"));
   }

    public void testBasicValidUrlWithLongStem()
    {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("http://testurl.com/test/me/today"));
    }

    public void testBasicValidUrlWithQueryParameter()
    {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("http://testurl.com/test?answerToLife=42"));
    }

    public void testBasicValidUrlWithFragment()
    {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("http://testurl.com/test#thisValidatorShouldWork"));
    }

    public void testBasicValidUrlWithUser()
    {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("http://nathan@testurl.com"));
    }

    public void testBasicValidUrlWithUserAndPassword()
    {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("http://nathan:testpass@testurl.com"));
            Assert.assertTrue(false);
    }


    public void testInvalidUrlNoSlashes()
    {
        try
        {
            UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
            assertTrue(!validator.isValid("http:testurl.com"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }

    public void testInvalidUrlTooManySlashes()
    {
        try
        {
            UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
            assertTrue(!validator.isValid("http:////testurl.com"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }

    public void testInvalidUrlAlphaPortNum()
    {
        try
        {
            UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
            assertTrue(!validator.isValid("http://testurl.com:test"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }

    public void testInvalidUrlNumericScheme()
    {
        try
        {
            UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
            assertTrue(!validator.isValid("3ttp://testurl.com"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }


    public void testInvalidUrlSpacesInPath()
    {
        try
        {
            UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
            assertTrue(!validator.isValid("http://testurl.com/this has some spaces"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }


    public void testInvalidUrlBadIPAddr()
    {
        try
        {
            UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
            assertTrue(!validator.isValid("ftp://1258.46.884.894"));
        }
        catch(Error e)
        {
            System.out.println("ERROR! Unhandled error thrown from url validator!!!");
            Assert.assertTrue(false);
        }
    }



    /*
        This is the large automated test we created.
        It uses a URL generator class that we wrote (UrlGenerator.java and Tuple.java) that
        creates URLs for testing.
     */
    @Test
    public void testWithUrlGenerator() throws RuntimeException
    {
        int errors = 0;
        int assertionError = 0;

        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        UrlGenerator generator = new UrlGenerator();

        Tuple<String, Boolean> url = generator.Next();
        while(url != null)
        {


            try
            {
                boolean valid = url.Second;
                boolean validatorReturned = validator.isValid(url.First);
                Assert.assertEquals(validatorReturned, valid);
            }
            catch(AssertionError e)
            {
                if(url.Second)
                {
                    System.out.printf("ERROR! %s should be valid = true, but was valid = false.", url.First);
                    System.out.println();
                }
                else
                {
                    System.out.printf("ERROR! %s should be valid = false, but was valid = true.", url.First);
                    System.out.println();
                }
                assertionError++;
            }
            catch(Error e)
            {
                System.out.printf("UNHANDLED ERROR thrown from validator ON: %s", url.First);
                System.out.println();
                errors++;
            }

            url = generator.Next();
        }

        System.out.printf("UNHANDLED ERRORS/EXCEPTIONS: %d", errors);
        System.out.println();
        System.out.printf("ASSERTION ERRORS: %d", assertionError);
        System.out.println();

        Assert.assertTrue(errors == 0);
        Assert.assertTrue(assertionError == 0);
    }
}
