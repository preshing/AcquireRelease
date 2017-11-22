#include "randomdelay.h"
#include <stdlib.h>
#include <assert.h>

int RandomDelay::g_randomValues[65536];

void RandomDelay::Initialize()
{
    for (int i = 0; i < 65536; i++)
        g_randomValues[i] = rand();
}

RandomDelay::RandomDelay(int step, int wrap) : m_pos(0), m_step(step), m_wrap(wrap)
{
    assert(step < kArraySize);
    assert(wrap < kArraySize);
}

void RandomDelay::doBusyWork()
{
    int i;
    do
    {
        i = g_randomValues[m_pos];
        m_pos += m_step;
        if (m_pos >= m_wrap)
            m_pos -= m_wrap;
    }
    while (i & 7);
}

