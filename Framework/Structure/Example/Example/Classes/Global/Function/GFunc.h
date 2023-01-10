#pragma once

#include "../Define/KGDefine.h"

namespace Global {
	/** 해시 슬롯을 생성한다 */
	STHSlot* CreateHSlot(void* a_pvKey, void* a_pvVal);

	/** 이진 트리 노드를 생성한다 */
	STBTreeNode* CreateBTNode(void* a_pvKey, void* a_pvVal);
}
