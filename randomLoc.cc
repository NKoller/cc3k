srand(time(NULL));

Coord randNum() {
 int x = rand() % chambers.size();
 auto vec = chambers [x];
 int y = rand() % vec.size();
 return vec[y];
}
