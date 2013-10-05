#ifndef SHAO_BING_H_INCLUDED
#define SHAO_BING_H_INCLUDED

#include "Character.h"


namespace DungeonHunter4
{

    // �ڱ�
    class ShaoBing : public Character
    {
    public:

        ShaoBing();

        void init();

        // �������ܣ���˪֮��
        void set_bing_shuang_zhi_jian();

        // �������ܣ�ӥ��
        void set_ying_yan();

        double get_adjustment();

        double get_yuan_su_shang_hai_jia_cheng();

        static double ge_max_dps();

    private:

        bool m_is_set_ying_yan; // �������ܣ�ӥ��
    };

} // namespace DungeonHunter4


#endif