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


    const Ring& Store::get_ring( const std::string& ring_name )
    {
        std::map<std::string, Ring*>::iterator find_it = m_ring_map.find( ring_name );

        if ( find_it == m_ring_map.end() )
        {
            assert( false );
        }

        return *(find_it->second);
    }


    std::map<std::string, WuQi*>& Store::get_all_wu_qi()
    {
        return m_wu_qi_map;
    }


    std::map<std::string, Ring*>& Store::get_all_ring()
    {
        return m_ring_map;
    }


    void Store::build_wu_qi()
    {
        m_wu_qi_map[ "圣洁弯弓" ]       = new WuQi( 72484, 85999 );
        m_wu_qi_map[ "食人魔长弓" ]     = new WuQi( 288, 327 );
        m_wu_qi_map[ "神圣长弓" ]       = new WuQi( 19209, 22685 );

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
        m_ring_map[ "灰烬之戒" ]     = new Ring( 0,    0,    0,   0.35, 0.00 );
        m_ring_map[ "蛇心指环" ]     = new Ring( 0,    0,    0,   0.11, 0.00 );
        m_ring_map[ "不老之戒" ]     = new Ring( 0,    0,    0,   0.11, 0.00 );
        m_ring_map[ "陨石指环" ]     = new Ring( 0,    0,    0,   0.35, 0.00 );
        //m_ring_map[ "赭石戒指" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "重环" ]         = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "奇异螺旋" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "蜥蜴之戒" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        m_ring_map[ "无名戒" ]       = new Ring( 0,    0,    0,   0.20, 0.00 );
        m_ring_map[ "莫比乌斯环" ]   = new Ring( 0,    0,    0,   0.20, 0.00 );
        m_ring_map[ "不朽之戒" ]     = new Ring( 0,    0,    805, 0.20, 0.00 );
        m_ring_map[ "精神之戒" ]     = new Ring( 0,    0.80, 0,   0.2,  0.00 );
        // m_ring_map[ "极地指环" ]     = new Ring( 0,    0.70, 637, 0,    0.07 ); //TODO
        m_ring_map[ "皇族之戒" ]     = new Ring( 0,    0.70, 0,   0.07, 0.00 );
        m_ring_map[ "圣力之戒" ]     = new Ring( 0,    0,    0,   0,    0.07 );
        // m_ring_map[ "女巫之戒" ]     = new Ring( 0,    0,    637, 0,    0.07 ); //TODO
        m_ring_map[ "污迹指环" ]     = new Ring( 0,    0,    0,   0.16, 0.00 );
        m_ring_map[ "云端指环" ]     = new Ring( 0.06, 0,    0,   0,    0.06 );
        //m_ring_map[ "坚韧指环" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "锯齿之环" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        m_ring_map[ "金属戒指" ]     = new Ring( 0.05, 0.50, 0,   0,    0.00 );
        //m_ring_map[ "君王指环" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "恶魔之戒" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        // m_ring_map[ "死亡象征" ]     = new Ring( 0,    0,    380, 0,    0.05 ); //TODO
        //m_ring_map[ "遗产之戒" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "野蛮之戒" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "科纳西趾环" ]   = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "漆黑之戒" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "祖传戒指" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "埋藏之戒" ]     = new Ring( 0,    0,    0,   0,    0.00 );
        //m_ring_map[ "锡戒指" ]       = new Ring( 0,    0,    0,   0,    0.00 );
        m_ring_map[ "公爵徽记之戒" ] = new Ring( 0,    0,    214, 0,    0.00 );
        //m_ring_map[ "" ]             = new Ring( 0,    0,    0,   0,    0.00 );
    }


    Store::Store()
    {
        build_wu_qi();
        build_ring();
    }

} // namespace DungeonHunter4
