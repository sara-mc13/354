void* balloc(int size) {
    //TODO: Your code goes in here.
    //checks size
    if (size <= 0) {
        return NULL;
    }
    blockHeader *current = heap_start;  //creates a current header variable
    blockHeader *bestFit = NULL;        //creates a best fit block
    size += siz;
    if (size % 8 != 0) {
        size = size + (8 - (size % 8));
    }
    //if size is larger than max size return null
    if (size > alloc_size) {
        return NULL;
    }
    //checks if current block is free
    while (1) {
        //checks if current is same size as requested
        if (current->size_status % 8 == 0 || current->size_status % 8== 2) {
            if ((current->size_status & ~3) - size == 0) {
                //sets best fit to current
                bestFit = current;
                //marks a bit as 1 (allocated)
                current->size_status = current->size_status + 1;
                //sets the p bit of next block to 1 (prev allocated)
                blockHeader *nextHeader = (blockHeader *)(((char*)current) + (current->size_status & (~3)));
                if (nextHeader < (blockHeader*)((char*)heap_start + alloc_size)) {
                    nextHeader->size_status = nextHeader->size_status | 2;
                }
                return (void*)(bestFit + 1);
            } else if ((current->size_status & ~3) - size > 0) {    //block is free but too big
                if (bestFit == NULL) {
                    bestFit = current;
                } else if ((current->size_status & (~3)) < (bestFit->size_status & (~3))) {     //if the current block is smaller than bestFit, replace
                    bestFit = current;
                }

            }
        }
        //sets current to point to next block
        current = (blockHeader*)((char*)current + (current->size_status & (~3)));

        //if current reaches end of heap, terminate loop
        if (current >= (blockHeader*)((char*)heap_start + alloc_size)) {
            //no best fit was found in heap
            if (bestFit == NULL) {
                return NULL;
            } else {
                int newSize = (bestFit->size_status & (~3)) - size;
                //if block big enough to split, split into two (one allocated and free)
                if (newSize > 8) {
                    blockHeader *newHeader = (blockHeader*)((char*)bestFit + size);
                    blockHeader *newFooter = (blockHeader*)((char*)newHeader + newSize - sizeof(blockHeader));
                    newHeader->size_status = newSize + 2;   //previous allocated, current free
                    newFooter->size_status = newSize;       //size of new block
                    bestFit->size_status = size | 3;
                } else {
                    //set a bit to 1
                    bestFit->size_status = bestFit->size_status | 1;
                    blockHeader* nextHeader = (blockHeader*)((char*)bestFit + (bestFit->size_status & (~3)));
                    if (nextHeader <(blockHeader*)((char*)heap_start + alloc_size)) {
                        nextHeader->size_status = nextHeader->size_status | 2;
                    }
                    return (void*)(bestFit + 1);
                }
            }
        }
    }
}
