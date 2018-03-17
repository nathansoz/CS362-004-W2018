

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
      //You can use this function to implement your manual testing
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }

   /*
        This is the programmatic testing section. I tend to prefer having several small unit tests that validate
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
        assertTrue(validator.isValid("https://testurl.com"));
    }

    public void testBasicValidUrlUncommonProtocol()
    {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("vsts://testurl.com"));
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
    }
}
