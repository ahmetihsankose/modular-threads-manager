/*
    Written by Ahmet Ihsan KOSE, Istanbul, Turkey
    Contact koseahmetihsan@gmail.com
*/

#pragma once
#include "ThreadBase.h"
#include <pthread.h>
#include <time.h>
#include "Logger.h"

class RealTimeThread : public ThreadBase
{
public:
    RealTimeThread() = default;
    ~RealTimeThread() = default;

    void setPeriod(unsigned int periodMs) override;

    bool setThreadPriority(int priority) override;
    bool setThreadAffinity(int cpuCore) override;
    
protected:
    void waitForNextPeriod();
    
    uint64_t getCurrentTimeNs();
    uint64_t mPeriodNs = 0;

private:

    unsigned int mLastExecutionTimeNs = 0;
};