struct agent newagent(int x, int y){
	struct agent createdAgent;
	createdAgent.x = x;
	createdAgent.y = y;
	return createdAgent;
}
void north(struct agent *a){
	a.y++;
}
void south(struct agent *a){
	a.y--;
}
void east(struct agent *a){
	a.x++;
}
void west(struct agent *a){
	a.x--;
}
double distance(struct agent a1, struct agent a2){
	return sqrt(pow(a1.x-a2.x,2),pow(a1.y-a2.y,2));
}
