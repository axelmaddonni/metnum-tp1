#!/bin/bash
#{ time for i in {1..100} ; do ../horno exp1s3.in /dev/null 0; done; } 2> exp1s3m0.time;
#{ time for i in {1..100} ; do ../horno exp1s3.in /dev/null 1; done; } 2> exp1s3m1.time;
#{ time for i in {1..100} ; do ../horno exp1s3.in /dev/null 2; done; } 2> exp1s3m2.time;
#
#{ time for i in {1..100} ; do ../horno exp1s10.in /dev/null 0; done; } 2> exp1s10m0.time;
#{ time for i in {1..100} ; do ../horno exp1s10.in /dev/null 1; done; } 2> exp1s10m1.time;
#{ time for i in {1..100} ; do ../horno exp1s10.in /dev/null 2; done; } 2> exp1s10m2.time;
#
#{ time for i in {1..100} ; do ../horno exp1s50.in /dev/null 0; done; } 2> exp1s50m0.time;
#{ time for i in {1..100} ; do ../horno exp1s50.in /dev/null 1; done; } 2> exp1s50m1.time;
#{ time for i in {1..100} ; do ../horno exp1s50.in /dev/null 2; done; } 2> exp1s50m2.time;
#
#{ time for i in {1..100} ; do ../horno exp1s100.in /dev/null 0; done; } 2> exp1s100m0.time;
#{ time for i in {1..100} ; do ../horno exp1s100.in /dev/null 1; done; } 2> exp1s100m1.time;
#{ time for i in {1..100} ; do ../horno exp1s100.in /dev/null 2; done; } 2> exp1s100m2.time;

{ time for i in {1..25} ; do ../horno exp1s3.in /dev/null 0; done; } 2> exp1m0.time;
{ time for i in {1..25} ; do ../horno exp1s3.in /dev/null 1; done; } 2> exp1m1.time;
{ time for i in {1..25} ; do ../horno exp1s3.in /dev/null 2; done; } 2> exp1m2.time;

{ time for i in {1..25} ; do ../horno exp1s10.in /dev/null 0; done; } 2>> exp1m0.time;
{ time for i in {1..25} ; do ../horno exp1s10.in /dev/null 1; done; } 2>> exp1m1.time;
{ time for i in {1..25} ; do ../horno exp1s10.in /dev/null 2; done; } 2>> exp1m2.time;

{ time for i in {1..25} ; do ../horno exp1s50.in /dev/null 0; done; } 2>> exp1m0.time;
{ time for i in {1..25} ; do ../horno exp1s50.in /dev/null 1; done; } 2>> exp1m1.time;
{ time for i in {1..25} ; do ../horno exp1s50.in /dev/null 2; done; } 2>> exp1m2.time;

{ time for i in {1..25} ; do ../horno exp1s100.in /dev/null 0; done; } 2>> exp1m0.time;
{ time for i in {1..25} ; do ../horno exp1s100.in /dev/null 1; done; } 2>> exp1m1.time;
{ time for i in {1..25} ; do ../horno exp1s100.in /dev/null 2; done; } 2>> exp1m2.time;
