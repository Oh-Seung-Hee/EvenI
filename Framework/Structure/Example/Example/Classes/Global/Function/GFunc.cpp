#include "GFunc.h"

namespace Global {
    STHSlot* CreateHSlot(void* a_pvKey, void* a_pvVal) {
        STHSlot* pstSlot = (STHSlot*)malloc(sizeof(STHSlot));
        pstSlot->m_pvKey = a_pvKey;
        pstSlot->m_pvVal = a_pvVal;
        pstSlot->m_eSlotState = EHSlotState::EMPTY;

        return pstSlot;
    }

    STBTreeNode* CreateBTNode(void* a_pvKey, void* a_pvVal) {
        STBTreeNode* pstNode = (STBTreeNode*)malloc(sizeof(STBTreeNode));
        pstNode->m_pvKey = a_pvKey;
        pstNode->m_pvVal = a_pvVal;
        pstNode->m_pstLChildNode = NULL;
        pstNode->m_pstRChildNode = NULL;

        return pstNode;
    }
}
