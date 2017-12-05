#!/bin/bash
{ time for i in {1..25} ; do ../horno exp3mx4.in /dev/null 0; done; } 2> exp3m0.time;
{ time for i in {1..25} ; do ../horno exp3mx4.in /dev/null 1; done; } 2> exp3m1.time;
{ time for i in {1..25} ; do ../horno exp3mx4.in /dev/null 2; done; } 2> exp3m2.time;

{ time for i in {1..25} ; do ../horno exp3nx2mx2.in /dev/null 0; done; } 2>> exp3m0.time;
{ time for i in {1..25} ; do ../horno exp3nx2mx2.in /dev/null 1; done; } 2>> exp3m1.time;
{ time for i in {1..25} ; do ../horno exp3nx2mx2.in /dev/null 2; done; } 2>> exp3m2.time;

{ time for i in {1..25} ; do ../horno exp3nx4.in /dev/null 0; done; } 2>> exp3m0.time;
{ time for i in {1..25} ; do ../horno exp3nx4.in /dev/null 1; done; } 2>> exp3m1.time;
{ time for i in {1..25} ; do ../horno exp3nx4.in /dev/null 2; done; } 2>> exp3m2.time;
