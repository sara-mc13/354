void* balloc(int size) {
    if(size<=0) { return NULL; }                        //Check size - Return NULL if not positive or if larger than heap space.
   size+=sizeof(blockHeader);                           //adding the size of the blockHeader(ie size of int) to size
   if(size%8!=0) {size = size + (8 - size % 8); }       //adding padding to make size a multiple of 8 if neccessary
  if(size > alloc_size) return NULL;                    //if size requested is greater than the maximum size we can allocate return NULL 

   //traversing through all the blocks on the heap and trying to find the BEST-FIT block
   blockHeader *currBlock = heap_start; //blockHeader* to iterate through the loop
   blockHeader *bestFitBlock = NULL;    //best-fit block
   while(1){
           //check to see if the current block is free
           if(currBlock->size_status % 8  == 0 || currBlock->size_status % 8 == 2){
                   //check to see if current block size is exactly the same as size that is required
                   //if it is, then we have found our BEST-FIT block
                   if((currBlock->size_status & ~3) - size == 0){
                           currBlock->size_status = currBlock->size_status + 1;  //set a bit to 1 to indicate that the current block is occupied
                           blockHeader *headerNextBlock = (blockHeader *)(((char*)currBlock) + (currBlock->size_status & (~3)));
                          if(headerNextBlock < (blockHeader*)((char*)heap_start + alloc_size)) { headerNextBlock->size_status =  headerNextBlock->size_status | 2; } //set p bit of next block to 1 to indicate previous block is occcupied
                         return (void*)(currBlock + 1);
                   } else if((currBlock->size_status & ~3) - size > 0){ //block is free but larger than required size
                           if(bestFitBlock == NULL) { bestFitBlock = currBlock; }
                           else if((currBlock->size_status & (~3)) < (bestFitBlock->size_status & (~3))) { bestFitBlock = currBlock; } //if size of current block is smaller than bestFitBlock, make it the //bestFitBlock
                   }
           }

           //updating the currentBlock pointer to point to the next block to iterate through the entire heap
           currBlock = (blockHeader*)((char*)currBlock + (currBlock->size_status & (~3)));
           //if currBlock > range of heap size then we have finished iterating through the entire heap
           if(currBlock >= (blockHeader*)((char*)heap_start + alloc_size)){
                   if(bestFitBlock == NULL){ return NULL; }  //cannot allocate as there is not enough contiguous space available in the heap
                   else{
                   //size of 2nd block
                   int sizeAfterAllocation = (bestFitBlock->size_status & (~3)) - size;
                   //if greater than minimum size of block, we can split this block into 2 blocks where 1 is allocated and the other is free
                   if(sizeAfterAllocation > minBlockSize){
                           blockHeader *newBlockHeader = (blockHeader*)((char*)bestFitBlock + size);
                           newBlockHeader->size_status = sizeAfterAllocation + 2; //indicate that previous block is occupied and this block is free
                           blockHeader *newBlockFooter = (blockHeader*)((char*)newBlockHeader + sizeAfterAllocation - sizeof(blockHeader));
                           newBlockFooter->size_status = sizeAfterAllocation; //size of the new block 
                           bestFitBlock->size_status = size | 3;
                   } else{
                           //new block is too small to form another block
                           bestFitBlock->size_status = bestFitBlock->size_status | 1; //set a bit to 1
                           blockHeader* nextBlockHeader = (blockHeader*)((char*)bestFitBlock + (bestFitBlock->size_status & (~3)));
                           //check to see if the nextBlockHeader is within heap bounds
                           if(nextBlockHeader < (blockHeader*)((char*)heap_start + alloc_size)) { nextBlockHeader->size_status = nextBlockHeader->size_status | 2; } //show that previous block is occupied
                   }
                   return (void*)(bestFitBlock + 1);
           }
           }
   }
}


int bfree(void *ptr) {
        if(ptr==NULL) return -1;        //Return -1 if ptr is NULL
        if((int)ptr % 8 !=0) return -1; //Return -1 if ptr is not a multiple of 8
        blockHeader* p = ptr - sizeof(blockHeader);
        if(p < heap_start || p >= (blockHeader*)((char*)heap_start + alloc_size)) { return -1; }  //Return -1 if ptr is outside of the heap space
        if(p->size_status % 8 == 0 || p->size_status % 8 == 2) { return -1; }   //Return -1 if ptr block is already freed.
        p->size_status = p->size_status & (~1);  //setting a bit to 0 to show block is now free
        blockHeader *newBlockFooter = (blockHeader*)((char*)p + (p->size_status & (~3)) -4);  //adding footer of the new freed block
        newBlockFooter->size_status = p->size_status & (~3); //setting size of footer
        //finding the next header and if it is wihtin the valid size set p bit to 0
        blockHeader* nextHeader = (blockHeader*)((char*)newBlockFooter + sizeof(blockHeader));
        if(nextHeader < (blockHeader*)((char*)heap_start + alloc_size)){ //if nextHeaper is in the heap space
       nextHeader->size_status = nextHeader->size_status & (~2); //set p bit to 1
        }
     return 0;
}





int coalesce() {
    //iterating through all the blocks on the heap
    //coalesce if next block and current block are both free
    blockHeader *currBlock = heap_start;
   while(currBlock < (blockHeader*)((char*)heap_start + alloc_size)){ //while currBlock is in the heap space
           blockHeader *nextBlockHeader = (blockHeader*)((char*)currBlock + (currBlock->size_status & (~3))); //blockHeader* to the next block
           //if the next block is in the heap space and both the current & next blocks are free
           if(nextBlockHeader < ((blockHeader*)((char*)heap_start + alloc_size)) && ((currBlock->size_status & 1) == 0) && ((nextBlockHeader->size_status & 1) == 0)){
           blockHeader* nextBlockFooter = nextBlockHeader + (nextBlockHeader->size_status & (~3)) - 4); //footer of next block
           blockHeader* currBlockFooter = (blockHeader*)((char*)currBlock + (currBlock->size_status & (~3))-4);               //footer of current block
           currBlockFooter=nextBlockFooter;                                                                                   //setting nextBlockFooter to currBlockFooter
           currBlockFooter->size_status = (currBlock->size_status & (~3)) + (nextBlockHeader->size_status & (~3));            //updating size of block
           currBlock->size_status = currBlockFooter->size_status | 2;                                                         //setting p bit to 1
           } else{ //iterate to next block
                   currBlock = (blockHeader*)((char*)currBlock + (currBlock->size_status & (~3)));
           }
   }
        return 0;

}


