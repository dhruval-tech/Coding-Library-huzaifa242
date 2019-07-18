//Usage centroid_decomposition c1(size,root);

//LCA stuff here
class centroid_decomposition
{
	private:
	int n,tot;
	vector<int> par,lvl,tsz,dead;
	void gettsz(int u,int pr)
	{
		tot++;
		tsz[u]=1;
		for(auto v:adjlst[u])
		{
			if(v!=pr && !dead[v])
			{
				gettsz(v,u);
				tsz[u]+=tsz[v];
			}
		}
	}
	int find_centroid(int u,int pr)
	{
		for(auto v:adjlst[u])
		{
			if(v!=pr && !dead[v])
			{
				if(tsz[v]>(tot/2))
				return find_centroid(v,u);
			}
		}
		return u;
	}
	void decompose(int u,int pr,int l)
	{
		tot=0;
		gettsz(u,0);
		int centro=find_centroid(u,0);
		par[centro]=pr;
		lvl[centro]=l;
		for(auto v:adjlst[u])
		{
			if(!dead[v])
			{
				dead[centro]=1;
				decompose(v,centro,l+1);
			}
		}
	}
	public:
	centroid_decomposition(int size,int root)
	{
		n=size;
		par.assign(n+1,0);
		lvl.reserve(n+1);
		tsz.reserve(n+1);
		dead.reserve(n+1,0);
		pre_lca(root);
		decompose(root,0,1);
	}
	int lca(int u,int v)
	{
		if(lvl[u]>lvl[v])
			swap(u,v);
		while(lvl[u]!=lvl[v])
			v=par[v];
		while(u!=v)
		{
			u=par[u];
			v=par[v];
		}
		return u;
	}
	void update(int u)
	{
		int v=u;
		while(1)
		{
			//update logic
			if(v==par[v])
				break;
			v=par[v];
		}
	}
	int query(int u)
	{
		int v=u;
		int ans=0;//Assign suitable value
		while(1)
		{
			//query logic
			if(v==par[v])
				break;
			v=par[v];
		}
		return ans;
	}
};