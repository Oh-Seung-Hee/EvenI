#include "GFunc.h"

namespace Global {
    STBTNode* CreateBTNode(void* a_pvKey, void* a_pvVal) {
        STBTNode* pstNode = (STBTNode*)malloc(sizeof(STBTNode));
        pstNode->m_pvKey = a_pvKey;
        pstNode->m_pvVal = a_pvVal;
        pstNode->m_pstLChildNode = NULL;
        pstNode->m_pstRChildNode = NULL;

        return pstNode;
    }
}
