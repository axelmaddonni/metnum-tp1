#!/bin/bash
{ time for i in {1..100} ; do ../horno exp2n1.in /dev/null 0; done; } 2> exp2m0.time;
{ time for i in {1..100} ; do ../horno exp2n1.in /dev/null 1; done; } 2> exp2m1.time;
{ time for i in {1..100} ; do ../horno exp2n1.in /dev/null 2; done; } 2> exp2m2.time;

{ time for i in {1..100} ; do ../horno exp2n2.in /dev/null 0; done; } 2>> exp2m0.time;
{ time for i in {1..100} ; do ../horno exp2n2.in /dev/null 1; done; } 2>> exp2m1.time;
{ time for i in {1..100} ; do ../horno exp2n2.in /dev/null 2; done; } 2>> exp2m2.time;

{ time for i in {1..100} ; do ../horno exp2n5.in /dev/null 0; done; } 2>> exp2m0.time;
{ time for i in {1..100} ; do ../horno exp2n5.in /dev/null 1; done; } 2>> exp2m1.time;
{ time for i in {1..100} ; do ../horno exp2n5.in /dev/null 2; done; } 2>> exp2m2.time;
                       
{ time for i in {1..100} ; do ../horno exp2n10.in /dev/null 0; done; } 2>> exp2m0.time;
{ time for i in {1..100} ; do ../horno exp2n10.in /dev/null 1; done; } 2>> exp2m1.time;
{ time for i in {1..100} ; do ../horno exp2n10.in /dev/null 2; done; } 2>> exp2m2.time;

{ time for i in {1..100} ; do ../horno exp2n50.in /dev/null 0; done; } 2>> exp2m0.time;
{ time for i in {1..100} ; do ../horno exp2n50.in /dev/null 1; done; } 2>> exp2m1.time;
{ time for i in {1..100} ; do ../horno exp2n50.in /dev/null 2; done; } 2>> exp2m2.time;
                       
{ time for i in {1..100} ; do ../horno exp2n100.in /dev/null 0; done; } 2>> exp2m0.time;
{ time for i in {1..100} ; do ../horno exp2n100.in /dev/null 1; done; } 2>> exp2m1.time;
{ time for i in {1..100} ; do ../horno exp2n100.in /dev/null 2; done; } 2>> exp2m2.time;
