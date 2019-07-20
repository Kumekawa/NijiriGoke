#include "Field.h"
#define FOR for(int i = 0;i < blocks.size();++i)\
		 for(int j = 0;j < blocks[i].size();++j)

Field::Field(int xNum, int yNum){
	for (int i = 0; i < xNum; ++i) {
		vector<Block> block;
		for (int j = 0; j < yNum; ++j) {
			block.push_back(Block(i * 100, j * 100));
		}
		blocks.push_back(block);
	}
}

void Field::Update(){
	FOR{
		blocks[i][j].Update();
	}
}

void Field::Draw(){
	FOR{
		blocks[i][j].Draw();
	}
}
