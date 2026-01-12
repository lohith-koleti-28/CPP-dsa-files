#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
using namespace std;
class Matrix{
   //-----------------------------
   //The row, column number and data of Array
   int r,c;
   vector<vector<double> > v;
   //-----------------------------
   public:

   friend ostream& operator<<(ostream & ost , const Matrix &m);

   friend istream& operator>>(istream& ist , Matrix &m);

   //-----------------------------


   Matrix& operator=(const Matrix &m){
      r = m.r;
      c = m.c;
      v.resize(r,vector<double> (c));
      for(int i=0;i<m.v.size();i++){
         for(int j=0;j<m.v[0].size();j++){
            v[i][j] = m.v[i][j];
         }
      }
      return *this;
   }

   //Constructor
   Matrix(int m=1,int n=1,int k=1): v(m ,vector<double> (n)) ,r(m),c(n){
      //If call has 1 then Identity
      //else full matrix with same number
      for(int i=0;i<v.size();i++){
         for(int j=0;j<v[0].size();j++){
            if(k ==1){
               if(i == j) v[i][i] = 1;
               else v[i][j] = 0;
            }
            else{
               v[i][j] = k;
            }

         }
      }
   }

   //Copy constructor
   Matrix(const Matrix &m){
      *this = m;
   }

   Matrix operator*(const Matrix &m){
      if(c == m.r){
         Matrix a(r,m.c,0);
         for(int i=0;i<a.r;i++){
            for(int j=0;j<a.c;j++){
               for(int k=0;k<m.r;k++){
                  a.v[i][j] += v[i][k] * m.v[k][j];
               }
            }
         }
         return a;
      }
   else return Matrix(r,c,0);
   }

   Matrix operator*(double f){
      Matrix a(r,c,0);
      for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            a.v[i][j] = f * v[i][j];
         }
      }
      return a;
   }

   Matrix operator+(Matrix m){
      if(r == m.r && c == m.c){
         Matrix a(r,c,0);
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               a.v[i][j] = v[i][j] + m.v[i][j];
            }
         }
         return a;
      }
      else return Matrix(r,c,0);
   }

   Matrix operator-(Matrix m){
      Matrix a(*this);
      m = m * -1.0;
      return a + m;
   }

   Matrix trans(){
      int temp = r;
      r = c;
      c = temp;
      Matrix m(r,c);
      for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            m.v[i][j] = v[j][i];
         }
      }
      return m;
   }

   bool operator==(const Matrix &m){
      if(r == m.r && c == m.c){
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(v[i][j] != m.v[i][j]) return 0;
            }
         }
         return 1;
      }
      else return 0;
   }

   void swap(int i, int j){
      //swaps ith row with jth row
      if(i != j){
         for(int k=0;k<c;k++){
            double temp = v[i][k];
            v[i][k] = v[j][k];
            v[j][k] = temp;
         }
      }
   }
   Matrix ref(){
      //Gives Row Echelon form of given matrix
      Matrix temp = *this;
      for(int i=0;i<r;i++){
         if(temp.v[i][0] != 0 ){
            temp.swap(i,0);
            break;
         }
      }

      for (int i = 0; i < r-1; ++i) {//I made a change r -> r-1
         double pivot = temp.v[i][i];
         // Scale the current row
         //Making a change of putting a condition on below loop
         if( abs(pivot) > 1E-6){
            for (int j = 0; j < c; ++j) {
               temp.v[i][j] /= pivot;
            }
         }
         // Eliminate other rows
         for (int k = 0; k < r; ++k) {
            if (k != i) {
                 double factor = temp.v[k][i];
                 for (int j = 0; j < c; ++j) {
                     temp.v[k][j] -= factor * temp.v[i][j];
                 }
            }
         }
      } 
      // cout<<"Pivots are: ";
      // for(int i=0;i<temp.r;i++){
      //    double pivot = 0;
      //    for(int j=0;j<temp.c;j++){
      //       if(abs(temp.v[i][j]) >= 1E-5){
      //          pivot = temp.v[i][j];
      //          break;
      //       }
      //    }
      //    if(abs(pivot) > 1E-5){
      //       cout<<pivot<<" ";
      //    }
      // }
      // cout<<endl;
      return temp;
   }
   int rank(){
      Matrix temp = this->ref();
      int ans=0;
      for(int i=0;i<temp.r;i++){
         bool found = false;
         for(int j=0;j<temp.c;j++){
            if(abs(temp.v[i][j]) >= 1e-5){
               found = true;
               
               break;
            }
         }
         if(found) ans++;
      }
      return ans;
   }

   Matrix inverse() {
        if (r != c) {
            cout << "Error: Matrix is not square. Inverse does not exist." << endl;
            exit(EXIT_FAILURE);
        }

        // Augmenting the matrix with the identity matrix
        Matrix augmented(r,2*c,0);
      //   vector<vector<double> > augmented(r, vector<double>(2 * c, 0.0));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                augmented.v[i][j] = v[i][j];
                augmented.v[i][j + c] = (i == j) ? 1.0 : 0.0;
            }
        }
        for(int i=0;i<r;i++){
         if(augmented.v[i][0] != 0 ){
            augmented.swap(i,0);
            break;
         }
        }
        // Applying Gauss-Jordan elimination
        for (int i = 0; i < r; ++i) {
            double pivot = augmented.v[i][i];

            // Scale the current row
            for (int j = 0; j < 2 * c; ++j) {
                augmented.v[i][j] /= pivot;
            }

            // Eliminate other rows
            for (int k = 0; k < r; ++k) {
                if (k != i) {
                    double factor = augmented.v[k][i];
                    for (int j = 0; j < 2 * c; ++j) {
                        augmented.v[k][j] -= factor * augmented.v[i][j];
                    }
                }
            }
        }

        Matrix ans(r,c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans.v[i][j] = augmented.v[i][j+c];
            }
        }
        return ans;
    }

   //-----------------------------
   //Elementary Operations on Matrices
   Matrix p(int i, int j){
      //Swaps ith row with jth row
      swap(i,j);
      return *this;
   }

   Matrix e(int i , int j, double c){
      //Adding c times jth row to ith row
      for(int k=0;k<c;k++){
         v[i][k] += c*v[j][k];
      }
      return *this;
   }

   Matrix m(int i,double k){
      //Multiplies ith row by k
      if( abs(k) < 1e-5) return *this;
      else{
         for(int j=0;j<c;j++){
            v[i][j] *= k;
         }
         return *this;
      }
   }
   //-----------------------------

   //Generic functions
   int getR(){
      return r;
   }

   int getC(){
      return c;
   }

   bool symmetric(){
      if( *this == this->trans()) return 1;
      return 0;
   }

   bool skewSymmetric(){
      Matrix a(*this);
      a = a * -1.0;
      if(*this == a.trans() )return 1;
      return 0;
   }
   void random(){
      srand(time(0));
      for(int i=0;i<r;i++){
         for(int j=0;j<c;j++){
            v[i][j] = int( 1+ 5.0*rand()/RAND_MAX);
         }
      }
   }
};

ostream& operator<<(ostream & ost , const Matrix &m){
   for(int i=0;i<m.r;i++){
      for(int j=0;j<m.c;j++){
         ost<<m.v[i][j]<<" ";
      }
      ost<<endl;
   }
   return ost;
}

istream& operator>>(istream& ist , Matrix &m){
   for(int i=0;i<m.r;i++){
      for(int j=0;j<m.c;j++){
         ist >> m.v[i][j];
      }
   }
   return ist;
}

int main(){
   int m, n;
   cin >> m >> n;
   Matrix a(m,n);
   a.random();
   cout<<a<<endl;
   cout<<a.ref()<<endl;
}