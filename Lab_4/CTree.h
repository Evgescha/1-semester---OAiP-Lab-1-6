//---------------------------------------------------------------------------

#ifndef CTreeH
#define CTreeH
//---------------------------------------------------------------------------
#endif

class CVetv
{
   public:
   int key;
	int inf;
   CVetv *l,*r;
   CVetv (int n, int key);

};
class CTree
{
 private:
   char * name;
   int n;
   CVetv *root;
  public:
  int SummUsel;
   CTree(char* n_name, int n_n , int n_key);
   ~CTree();
   CVetv* add(int i, int n_key);
   void del_vet(CVetv * dr);
   void view ( CVetv *t, int lv );
   void view_all ();
   CVetv* find(int fnd);
   CVetv* find(int fnd, CVetv * dr);

   int coll (int _lv );
   void usl ( CVetv *t, int lv);
};