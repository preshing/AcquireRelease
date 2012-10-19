#ifndef __RANDOM_DELAY_H__
#define __RANDOM_DELAY_H__


//-------------------------------------
//  RandomDelay
//-------------------------------------
class RandomDelay
{
private:
    static const int kArraySize = 65536;
    static int g_randomValues[kArraySize];
    
    unsigned int m_pos;
    unsigned int m_step;
    unsigned int m_wrap;
    
public:
    static void Initialize();
    
    RandomDelay(int step, int wrap);
    void doBusyWork();
};


#endif // __RANDOM_DELAY_H__
