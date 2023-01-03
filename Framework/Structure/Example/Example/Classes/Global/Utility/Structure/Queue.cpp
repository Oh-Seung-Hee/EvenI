#include "Queue.h"

namespace Global {
    /** 크기를 변경한다 */
    static void QResize(STQueue* a_pstQueue, int a_nSize) {
        void** pvVals = (void**)malloc(sizeof(void*) * a_nSize);

        for(int i = 0; i < a_nSize && i < a_pstQueue->m_nNumVals; ++i) {
            pvVals[i] = a_pstQueue->m_pvVals[(a_pstQueue->m_nFront + i) % a_pstQueue->m_nSize];
        }

        SAFE_FREE(a_pstQueue->m_pvVals);

        a_pstQueue->m_nSize = a_nSize;
        a_pstQueue->m_nNumVals = (a_nSize < a_pstQueue->m_nNumVals) ? a_nSize : a_pstQueue->m_nNumVals;

        a_pstQueue->m_nRear = a_pstQueue->m_nNumVals % a_nSize;
        a_pstQueue->m_nFront = 0;

        a_pstQueue->m_pvVals = pvVals;
    }

    void QInit(STQueue* a_pstQueue) {
        memset(a_pstQueue, 0, sizeof(STQueue));

        a_pstQueue->m_nSize = 5;
        a_pstQueue->m_pvVals = (void**)malloc(sizeof(void*) * a_pstQueue->m_nSize);
    }

    void QDestroy(STQueue* a_pstQueue) {
        SAFE_FREE(a_pstQueue->m_pvVals);
    }

    bool QIsEmpty(STQueue* a_pstQueue) {
        return a_pstQueue->m_nNumVals <= 0;
    }

    void* QPeek(STQueue* a_pstQueue) {
        assert(!QIsEmpty(a_pstQueue));
        return a_pstQueue->m_pvVals[a_pstQueue->m_nFront];
    }

    void QEnqueue(STQueue* a_pstQueue, void* a_pvVal) {
        // 큐가 가득 찼을 경우
        if(a_pstQueue->m_nNumVals >= a_pstQueue->m_nSize) {
            QResize(a_pstQueue, a_pstQueue->m_nSize * 2);
        }

        a_pstQueue->m_pvVals[a_pstQueue->m_nRear] = a_pvVal;

        a_pstQueue->m_nRear = (a_pstQueue->m_nRear + 1) % a_pstQueue->m_nSize;
        a_pstQueue->m_nNumVals += 1;
    }

    void* QDequeue(STQueue* a_pstQueue) {
        assert(!QIsEmpty(a_pstQueue));
        void* pvVal = a_pstQueue->m_pvVals[a_pstQueue->m_nFront];

        a_pstQueue->m_nFront = (a_pstQueue->m_nFront + 1) % a_pstQueue->m_nSize;
        a_pstQueue->m_nNumVals -= 1;

        return pvVal;
    }
}
