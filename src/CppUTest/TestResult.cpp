/*
 * Copyright (c) 2007, Michael Feathers, James Grenning and Bas Vodde
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "TestResult.h"
#include "Failure.h"
#include "TestOutput.h"
#include <stdio.h>


TestResult::TestResult (TestOutput& p)
    : output(p)
    , testCount(0)
    , runCount(0)
    , checkCount(0)
    , failureCount (0)
    , filteredOutCount(0)
    , ignoredCount(0)
{}


TestResult::~TestResult()
{}


void TestResult::testsStarted ()
{}


void TestResult::addFailure (const Failure& failure)
{
  failure.Print(output);
  failureCount++;
}

void TestResult::countTest()
{
  testCount++;
}

void TestResult::countRun()
{
  runCount++;
}

void TestResult::countCheck()
{
  checkCount++;
}

void TestResult::countFilteredOut()
{
  filteredOutCount++;
}

void TestResult::countIgnored()
{
  ignoredCount++;
}

void TestResult::testsEnded ()
{
  if (failureCount > 0)
    {
      output.print("\nErrors (");
      output.print(failureCount);
      output.print(" failures, ");
    }
  else
    {
      output.print("\nOK (");
    }
  output.print(testCount);
  output.print(" tests, ");
  output.print(runCount);
  output.print(" ran, ");
  output.print(checkCount);
  output.print(" checks, ");
  output.print(ignoredCount);
  output.print(" ignored, ");
  output.print(filteredOutCount);
  output.print(" filtered out)\n\n");
}