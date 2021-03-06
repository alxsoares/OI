#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

const int P_MAX = 10017;
const int L_MAX = 2100000;
const int HASH_SIZE = 1 << 16;

int P, L, loop, appear_size;
int appear[L_MAX];

struct Matrix {
	int ele[3][3];
	bool operator< (const Matrix &t) const {
		for ( int i = 0; i < 3; i ++ )
			for ( int j = 0; j < 3; j ++ )
				if ( ele[i][j] < t.ele[i][j] )
					return true;
				else if ( ele[i][j] > t.ele[i][j] )
					return false;	
		return false;
	}
	bool operator== (const Matrix &t) const {
		return !(t < (*this)) && ! ((*this) < t);
	}
	int hash() const{
		int res = 0;
		for ( int i = 0; i < 3; i ++ )
			for ( int j = 0; j < 3; j ++ )
				res ^= (ele[i][j] << (i + i + i + j));
		return res;
	}
} id_mat, trans_mat, inv_mat;

struct HashMap {
	int begin[HASH_SIZE], next[L_MAX], key[L_MAX];
	Matrix val[L_MAX];
	int size;
	void clear() {
		memset(begin, -1, sizeof(begin));
		memset(next, -1, sizeof(next));
		size = 0;
	}
	int &operator[] (const Matrix &it) {
		int code = it.hash() & (HASH_SIZE - 1);
		for ( int e = begin[code]; e != -1; e = next[e] ) 
			if ( val[e] == it )
				return key[e];
		val[size] = it;
		key[size] = -1;
		next[size] = begin[code];
		begin[code] = size;
		size ++;
		return key[size - 1];
	}
} HM;

Matrix mat_mul(const Matrix &A, const Matrix &B) {
	Matrix C;
	for ( int i = 0; i < 3; i ++ )
		for ( int j = 0; j < 3; j ++ ) {
			C.ele[i][j] = 0;
			for ( int k = 0; k < 3; k ++ )
				C.ele[i][j] += A.ele[i][k] * B.ele[k][j];
			C.ele[i][j] %= P;
		}
	return C;
}

Matrix mat_pow(Matrix A, ll n) {
	Matrix res = n & 1 ? A : id_mat;
	for ( n >>= 1; n; n >>= 1 ) {
		A = mat_mul(A, A);
		if ( n & 1 ) 
			res = mat_mul(res, A);
	}
	return res;
}

int mat_log(const Matrix &des) {
	Matrix acc_mat = id_mat,
		   T = mat_pow(inv_mat, L);
	for ( int e = 0; e * L <= P * P; e ++ ) {
		Matrix X = mat_mul(acc_mat, des);
		if ( HM[X] != -1 )
			return e * L + HM[X];
		acc_mat = mat_mul(acc_mat, T);
	}
	return -1;
}

int pow_mod(int a, int n) {
	int res = n & 1 ? a : 1;
	for ( n >>= 1; n; n >>= 1 ) {
		a = a * a % P;
		if ( n & 1 )
			res = res * a % P;
	}
	return res;
}

int A, B, X, Y, Z, C, Q;
int S[P_MAX];

void special_work() {
	if ( X == 0 ) {
		S[3] = Z;
		while ( Q -- ) {
			ll l, r;
			ll res = 0;
			scanf("%lld%lld", &l, &r);
			if ( l < 3 && r < 3 ) {
				for ( int i = l; i <= r; i ++ )
				   res += S[i] == C;	
			} else {
				if ( l == 1 ) {
					res += A == C;
					res += B == C;
					l = 3;
				} else if ( l == 2 ) {
					res += B == C;
					l = 3;
				}
				if ( Z == C )
					res += r - l + 1;
			}
			printf("%lld\n", res);
		}
		return;
	}
	S[1] = A, S[2] = B;
	for ( int i = 3; ; i ++ ) {
		S[i] = (S[i - 1] * X + Z) % P;
		if ( S[i] == B ) {
			loop = i - 2;
			break;
		}
	}
	for ( int i = 2; i <= loop + 1; i ++ )
		if ( S[i] == C )
			appear[appear_size ++] = i - 1;
}

void normal_work() {
	L = P * (int)sqrt(P) + 1;
	memset(id_mat.ele, 0, sizeof(id_mat.ele));
	for ( int i = 0; i < 3; i ++ )
		id_mat.ele[i][i] = 1;

	memset(trans_mat.ele, 0, sizeof(trans_mat.ele));
	trans_mat.ele[0][1] = trans_mat.ele[2][2] = 1;
	trans_mat.ele[1][0] = Y;
	trans_mat.ele[1][1] = X;
	trans_mat.ele[1][2] = Z;

	memset(inv_mat.ele, 0, sizeof(inv_mat.ele));
	inv_mat.ele[0][0] = (P - X) * pow_mod(Y, P - 2) % P;
	inv_mat.ele[0][1] = pow_mod(Y, P - 2) % P;
	inv_mat.ele[0][2] = (P - Z) * pow_mod(Y, P - 2) % P;
	inv_mat.ele[1][0] = 1;
	inv_mat.ele[2][2] = 1;


	Matrix init_mat;
	memset(init_mat.ele, 0, sizeof(init_mat));
	init_mat.ele[0][0] = A;
	init_mat.ele[1][0] = B;
	init_mat.ele[2][0] = 1;

	assert(mat_mul(trans_mat, inv_mat) == id_mat);

	HM.clear();
	Matrix acc_mat = id_mat;
	for ( int i = 0; i < L; i ++ ) {
		Matrix tmp_mat = mat_mul(acc_mat, init_mat);
		if ( HM[tmp_mat] == -1)
			HM[tmp_mat] = i;
		acc_mat = mat_mul(acc_mat, trans_mat);
	}

	loop = -1;
	if ( loop == -1 ) {
		acc_mat = id_mat;
		for ( int i = 1; i <= L; i ++ ) {
			acc_mat = mat_mul(acc_mat, trans_mat);
			if ( mat_mul(acc_mat, init_mat) == init_mat ) {
				loop = i;
				break;
			}
		}
	}
	if ( loop == -1 ) {
		acc_mat = id_mat;
		Matrix T = mat_pow(inv_mat, L);
		for ( int e = 1; e * L <= P * P; e ++ ) {
			acc_mat = mat_mul(acc_mat, T);
			Matrix X = mat_mul(acc_mat, init_mat);
			if ( HM[X] != -1 ) {
				loop = e * L + HM[X];
				break;
			}
		}
	}
	appear_size = 0;
	for ( int i = 0; i < P; i ++ ) {
		Matrix tmp_mat;
		memset(tmp_mat.ele, 0, sizeof(tmp_mat.ele));
		tmp_mat.ele[0][0] = C;
		tmp_mat.ele[1][0] = i;
		tmp_mat.ele[2][0] = 1;
		int res = mat_log(tmp_mat);
		if ( res != -1 )
			appear[appear_size ++] = res + 1;
	}
	sort(appear, appear + appear_size);
}

void pre_work() {
	scanf("%d%d%d%d%d%d%d%d", &A, &B, &X, &Y, &Z, &P, &C, &Q);
	appear_size = 0;
	if ( Y == 0 )
		special_work();
	else
		normal_work();
}

void ans_query() {
	while ( Q > 0 ) {
		Q --;
		ll l, r;
		scanf("%lld%lld", &l, &r);
		ll res = 0;
		if ( Y == 0 ) {
			l --, r --;
			if ( l == 0 ) {
				res += A == C;
				l = 1;
			}
		}
		if ( l > r ) {
			printf("%lld\n", res);
			continue;
		}
		ll lpos = (l - 1) % loop + 1,
		   rpos = (r - 1) % loop + 1;
#define IN_RANGE(x) (0 <= (x) && (x) < appear_size)
		if ( (r - 1) / loop == (l - 1) / loop ) {
			int lb = -1, rb = appear_size - 1;
			for ( int mid = (lb + rb) / 2; lb < rb - 1; mid = (lb + rb) / 2 )
				if ( appear[mid] >= lpos )
					rb = mid;
				else
					lb = mid;
			if ( IN_RANGE(rb) && appear[rb] >= lpos ) {

				int tmp = rb;
				lb = 0, rb = appear_size;
				for ( int mid = (lb + rb) / 2; lb < rb - 1; mid = (lb + rb) / 2 )
					if ( appear[mid] <= rpos )
						lb = mid;
					else
						rb = mid;
				if ( IN_RANGE(lb) && appear[lb] <= rpos && tmp <= lb )
					res += lb - tmp + 1;
			}
		} else {
			ll cnt = (r - 1) / loop - (l - 1) / loop - 1;
			if ( cnt > 0 )
				res += cnt * appear_size;
			int lb = -1, rb = appear_size - 1;
			for ( int mid = (lb + rb) / 2; lb < rb - 1; mid = (lb + rb) / 2 )
				if ( appear[mid] >= lpos )
					rb = mid;
				else
					lb = mid;
			if ( IN_RANGE(rb) && appear[rb] >= lpos )
				res += appear_size - rb;
			lb = 0, rb = appear_size;
			for ( int mid = (lb + rb) / 2; lb < rb - 1; mid = (lb + rb) / 2 )
				if ( appear[mid] <= rpos )
					lb = mid;
				else
					rb = mid;
			if ( IN_RANGE(lb) && appear[lb] <= rpos )
				res += lb + 1;
		}
		printf("%lld\n", res);
	}
}

int main() {
	freopen("t.in", "r", stdin);
	int TST;
	scanf("%d", &TST);
	while ( TST -- ) {
		pre_work();
		ans_query();
	}
}
