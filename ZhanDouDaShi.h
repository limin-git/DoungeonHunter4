#ifndef ZHAN_DOU_DA_SHI_H_INCLUDED
#define ZHAN_DOU_DA_SHI_H_INCLUDED

#include "Character.h"


namespace DungeonHunter4
{

    // 战斗大师
    class ZhanDouDaShi : public Character
    {
    public:

        ZhanDouDaShi();

        void init();

        // 被动技能：愤怒
        void set_fen_nu();

        // 被动技能：技术老手
        void set_ji_shu_lao_shou();

        // 药剂：疾速药剂
        virtual void set_ji_su_yao_ji();

        // 药剂：士兵伤害
        virtual void set_shi_bing_shang_hai();

        static double ge_max_dps( size_t output_list_size = 10 );
    };

} // namespace DungeonHunter4


#endif
