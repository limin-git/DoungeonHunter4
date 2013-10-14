#ifndef SHAO_BING_H_INCLUDED
#define SHAO_BING_H_INCLUDED

#include "Character.h"


namespace DungeonHunter4
{

    // 哨兵
    class ShaoBing : public Character
    {
    public:

        ShaoBing();

        void init();

        // 被动技能：冰霜之箭
        void set_bing_shuang_zhi_jian();

        // 被动技能：鹰眼
        void set_ying_yan();

        // 主动技能：疾行
        void set_ji_xing();

        double get_yuan_su_shang_hai_jia_cheng();

        static double ge_max_dps( size_t output_list_size = 100 );

    private:

        bool m_is_set_ying_yan; // 被动技能：鹰眼
    };

} // namespace DungeonHunter4


#endif
