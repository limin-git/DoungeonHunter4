#include "stdafx.h"
#include "Store.h"


namespace DungeonHunter4
{

    Store& Store::instance()
    {
        static Store store;
        return store;
    }


    const WuQi& Store::get_wu_qi( const std::string& wu_qi_name )
    {
        std::map<std::string, WuQi*>::iterator find_it = m_wu_qi_map.find( wu_qi_name );

        if ( find_it == m_wu_qi_map.end() )
        {
            assert( false );
        }

        return *(find_it->second);
    }


    const Ring& Store::get_ring( const std::string& name )
    {
        for ( Rings::iterator it = m_rings.begin(); it != m_rings.end(); ++it )
        {
            if ( it->m_name == name )
            {
                return *it;
            }
        }

        assert( false );
        static Ring ring;
        return ring;
    }


    std::map<std::string, WuQi*>& Store::get_all_wu_qi()
    {
        return m_wu_qi_map;
    }


    Rings& Store::get_all_rings()
    {
        return m_rings;
    }


    void Store::build_wu_qi()
    {
        m_wu_qi_map[ "圣洁弯弓" ]       = new WuQi( 72484, 85999 );
        m_wu_qi_map[ "食人魔长弓" ]     = new WuQi( 288, 327 );
        m_wu_qi_map[ "神圣长弓" ]       = new WuQi( 19209, 22685 );
        m_wu_qi_map[ "毒域长弓" ]       = new WuQi( 9647, 11411 );

        m_wu_qi_map[ "圣洁长剑" ]       = new WuQi( 113028, 136196 );
        m_wu_qi_map[ "神圣宽剑" ]       = new WuQi( 29636, 35593 );
        m_wu_qi_map[ "食人魔大剑" ]     = new WuQi( 406, 474 );
    }


    void Store::build_ring()
    {
#if 0
        Ring;
        double bao_ji_ji_lu_jia;             // 暴击几率
        double bao_ji_jiang_li_jia;          // 暴击奖励
        double ji_chu_shang_hai_jia;         // 基础伤害
        double yuan_su_shang_hai_jia_cheng;  // 元素伤害加成
        double ji_chu_shang_hai_jia_cheng;   // 伤害加成
#endif
        m_rings.insert( Ring( 99, "灰烬之戒",     0,    0,    0,   0.35, 0.00 ) );
        m_rings.insert( Ring( 98, "不老之戒",     0,    0,    0,   0.11, 0.00 ) );
        m_rings.insert( Ring( 97, "蛇心指环",     0,    0,    0,   0.11, 0.00 ) );
        m_rings.insert( Ring( 96, "陨石指环",     0,    0,    0,   0.35, 0.00 ) );
        //m_rings.insert( Ring( 87, "赭石戒指",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 86, "重环",         0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 85, "奇异螺旋",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 84, "蜥蜴之戒",     0,    0,   0,    0,    0.00 ) );
        m_rings.insert( Ring( 75, "无名戒",       0,    0,    0,   0.20, 0.00 ) );
        m_rings.insert( Ring( 74, "莫比乌斯环",   0,    0,    0,   0.20, 0.00 ) );
        m_rings.insert( Ring( 73, "不朽之戒",     0,    0,    805, 0.20, 0.00 ) ); //TODO
        m_rings.insert( Ring( 72, "精神之戒",     0,    0.80, 0,   0.2,  0.00 ) );
        m_rings.insert( Ring( 63, "极地指环",     0,    0.70, 637, 0,    0.07 ) ); //TODO
        m_rings.insert( Ring( 62, "皇族之戒",     0,    0.70, 0,   0.07, 0.00 ) );
        m_rings.insert( Ring( 61, "圣力之戒",     0,    0,    0,   0,    0.07 ) );
        m_rings.insert( Ring( 60, "女巫之戒",     0,    0,    637, 0,    0.07 ) ); //TODO
        m_rings.insert( Ring( 51, "污迹指环",     0,    0,    0,   0.16, 0.00 ) );
        m_rings.insert( Ring( 50, "云端指环",     0.06, 0,    0,   0,    0.06 ) );
        //m_rings.insert( Ring( 49, "坚韧指环",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 48, "锯齿之环",     0,    0,    0,   0,    0.00 ) );
        m_rings.insert( Ring( 40, "金属戒指",     0.05, 0.50, 0,   0,    0.00 ) );
        //m_rings.insert( Ring( 39, "君王指环",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 38, "恶魔之戒",     0,    0,    0,   0,    0.00 ) );
        m_rings.insert( Ring( 37, "死亡象征",     0,    0,    380, 0,    0.05 ) ); //TODO
        //m_rings.insert( Ring( 28, "遗产之戒",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 27, "野蛮之戒",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 26, "科纳西趾环",   0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 25, "漆黑之戒",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 16, "祖传戒指",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 15, "埋藏之戒",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 14, "锡戒指",       0,    0,    0,   0,    0.00 ) );
        m_rings.insert( Ring( 13, "公爵徽记之戒", 0,    0,    214, 0,    0.00 ) );
    }


    Store::Store()
    {
        build_wu_qi();
        build_ring();
    }

} // namespace DungeonHunter4
