package com.isaiah_solo.library;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Unit test for simple App.
 */
public class RandBoxTest extends TestCase {

    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public RandBoxTest(String testName) {
        super(testName);
    }

    /**
     * @return the suite of tests being tested
     */
    public static Test suite() {
        return new TestSuite(RandBoxTest.class);
    }

    /**
     * Rigourous Test :-)
     */
    public void testApp() {
        assertTrue(true);
    }

/*
    public void testSizeInit() {
        RandBox box = new RandBox();
        assertEquals(0, box.size());
    }
*/
}
