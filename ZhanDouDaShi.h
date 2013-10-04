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

        static double ge_max_dps();
    };

} // namespace DungeonHunter4


#endif
