//dsu(cp-algo)

int parent[100], siz[100];
void make_set(int v)
{
	parent[v] = v;
	siz[v] = 1;
}
int find_set(int v)
{
	if(v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}
void dsu(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
	if(siz[a] < siz[b]) swap(a,b);
	parent[b] = a;
	siz[a] += siz[b];
    }
}
