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

        // 主动技能：疾行
        void set_ji_xing();

        // 被动技能：冰霜之箭
        void set_bing_shuang_zhi_jian();

        // 被动技能：鹰眼
        void set_ying_yan();

        // 药剂：疾速药剂
        virtual void set_ji_su_yao_ji();

        // 药剂：士兵伤害
        virtual void set_shi_bing_shang_hai();

        static double ge_max_dps( size_t output_list_size = 10 );

    private:

        bool m_is_set_ying_yan; // 被动技能：鹰眼
    };

} // namespace DungeonHunter4


#endif
