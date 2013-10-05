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
        m_wu_qi_map[ "ʥ���乭" ]       = new WuQi( 72484, 85999 );
        m_wu_qi_map[ "ʳ��ħ����" ]     = new WuQi( 288, 327 );
        m_wu_qi_map[ "��ʥ����" ]       = new WuQi( 19209, 22685 );
        m_wu_qi_map[ "���򳤹�" ]       = new WuQi( 9647, 11411 );

        m_wu_qi_map[ "ʥ�೤��" ]       = new WuQi( 113028, 136196 );
        m_wu_qi_map[ "��ʥ��" ]       = new WuQi( 29636, 35593 );
        m_wu_qi_map[ "ʳ��ħ��" ]     = new WuQi( 406, 474 );
    }


    void Store::build_ring()
    {
#if 0
        Ring;
        double bao_ji_ji_lu_jia;             // ��������
        double bao_ji_jiang_li_jia;          // ��������
        double ji_chu_shang_hai_jia;         // �����˺�
        double yuan_su_shang_hai_jia_cheng;  // Ԫ���˺��ӳ�
        double ji_chu_shang_hai_jia_cheng;   // �˺��ӳ�
#endif
        m_rings.insert( Ring( 99, "�ҽ�֮��",     0,    0,    0,   0.35, 0.00 ) );
        m_rings.insert( Ring( 98, "����֮��",     0,    0,    0,   0.11, 0.00 ) );
        m_rings.insert( Ring( 97, "����ָ��",     0,    0,    0,   0.11, 0.00 ) );
        m_rings.insert( Ring( 96, "��ʯָ��",     0,    0,    0,   0.35, 0.00 ) );
        //m_rings.insert( Ring( 87, "��ʯ��ָ",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 86, "�ػ�",         0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 85, "��������",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 84, "����֮��",     0,    0,   0,    0,    0.00 ) );
        m_rings.insert( Ring( 75, "������",       0,    0,    0,   0.20, 0.00 ) );
        m_rings.insert( Ring( 74, "Ī����˹��",   0,    0,    0,   0.20, 0.00 ) );
        m_rings.insert( Ring( 73, "����֮��",     0,    0,    805, 0.20, 0.00 ) ); //TODO
        m_rings.insert( Ring( 72, "����֮��",     0,    0.80, 0,   0.2,  0.00 ) );
        m_rings.insert( Ring( 63, "����ָ��",     0,    0.70, 637, 0,    0.07 ) ); //TODO
        m_rings.insert( Ring( 62, "����֮��",     0,    0.70, 0,   0.07, 0.00 ) );
        m_rings.insert( Ring( 61, "ʥ��֮��",     0,    0,    0,   0,    0.07 ) );
        m_rings.insert( Ring( 60, "Ů��֮��",     0,    0,    637, 0,    0.07 ) ); //TODO
        m_rings.insert( Ring( 51, "�ۼ�ָ��",     0,    0,    0,   0.16, 0.00 ) );
        m_rings.insert( Ring( 50, "�ƶ�ָ��",     0.06, 0,    0,   0,    0.06 ) );
        //m_rings.insert( Ring( 49, "����ָ��",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 48, "���֮��",     0,    0,    0,   0,    0.00 ) );
        m_rings.insert( Ring( 40, "������ָ",     0.05, 0.50, 0,   0,    0.00 ) );
        //m_rings.insert( Ring( 39, "����ָ��",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 38, "��ħ֮��",     0,    0,    0,   0,    0.00 ) );
        m_rings.insert( Ring( 37, "��������",     0,    0,    380, 0,    0.05 ) ); //TODO
        //m_rings.insert( Ring( 28, "�Ų�֮��",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 27, "Ұ��֮��",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 26, "������ֺ��",   0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 25, "���֮��",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 16, "�洫��ָ",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 15, "���֮��",     0,    0,    0,   0,    0.00 ) );
        //m_rings.insert( Ring( 14, "����ָ",       0,    0,    0,   0,    0.00 ) );
        m_rings.insert( Ring( 13, "�����ռ�֮��", 0,    0,    214, 0,    0.00 ) );
    }


    Store::Store()
    {
        build_wu_qi();
        build_ring();
    }

} // namespace DungeonHunter4
