#include "Field.h"
#include "Nijirigoke.h"
#define FOR for(int i = 0;i < blocks.size();++i)\
		 for(int j = 0;j < blocks[i].size();++j)

Field::Field(){
	for (int i = 0; i < FIELD_X; ++i) {
		vector<Block> block;
		for (int j = 0; j < FIELD_Y; ++j) {
			block.push_back(Block(i * FIELD_BLOCK_SIZE, j * FIELD_BLOCK_SIZE));
		}
		blocks.push_back(block);
	}
}

void Field::Update(){
	FOR{
		blocks[i][j].Update();
		if (blocks[i][j].GetMonsterF()) {
			monsters.push_back(Nijirigoke(&blocks,blocks[i][j].GetNourishment(), blocks[i][j].GetMagic(),i * FIELD_BLOCK_SIZE ,j * FIELD_BLOCK_SIZE));
		}
	}
	for (int i = 0; i < monsters.size(); ++i) {
		monsters[i].Update();
	}
}

void Field::Draw(){
	FOR{
		blocks[i][j].Draw();
	}
	for (int i = 0; i < monsters.size(); ++i) {
		monsters[i].Draw();
	}
}
