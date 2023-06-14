/******************************************************************************
  Contributors:
    Andreas Hadjigeorgiou, The Cyprus Institute, https://ahadji05.github.io

  Contact:
    a.hadjigeorgiou@cyi.ac.cy

  Copyright [2021] [CaSToRC (Cyprus Institute), Delphi Consortium (TU Delft)]

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
******************************************************************************/
#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

// timer uses milliseconds to catch floating point precision later
// when we want to summarize all timings before exit in seconds.
class timer
{

  public:
    std::chrono::system_clock::time_point clickStart;
    std::chrono::system_clock::time_point clickStop;
    std::chrono::duration<double, std::milli> elapsed;
    std::string name;
    int ncalls;
    double t_sum_milli;
    double t_sum_seconds;

    timer()
    {
        ncalls = 0;
        t_sum_milli = 0.0;
        t_sum_seconds = 0.0;
    }

    timer(const std::string &name) : name(name)
    {
        this->restart();
    }

    ~timer(){};

    void start()
    {
        ncalls += 1;
        clickStart = std::chrono::high_resolution_clock::now();
    }

    void stop()
    {
        clickStop = std::chrono::high_resolution_clock::now();
        elapsed = clickStop - clickStart;
        t_sum_milli += (double)(elapsed.count());
        t_sum_seconds = t_sum_milli / 1000.0;
    }

    void restart()
    {
        ncalls = 0;
        t_sum_milli = 0.0;
        t_sum_seconds = 0.0;
    }

    void set_name(const std::string &name)
    {
        this->name = name;
    }

    void dispInfo()
    {
        std::cout << name << ": ";
        std::cout << "calls(" << ncalls << ") total ";
        std::cout << t_sum_seconds << " seconds." << std::endl;
    }

    void exportInfo(std::fstream &f)
    {
        f << name << " " << ncalls << " " << t_sum_seconds << std::endl;
    }
};

#endif