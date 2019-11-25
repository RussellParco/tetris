#ifndef CELL
#define CELL
	class Cell{
		char content;
		*Block block;
		public:
		*Block getBlock();
		void setBlock();
		char getContent();
		void setContent();

	};

#endif
