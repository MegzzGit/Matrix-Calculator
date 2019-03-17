#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
float det(int b, float a[100][100])
{   
	float mat[100][100], d = 0;

	if (b == 1)
		d = a[0][0];

	else if (b == 2)
		d = a[0][0] * a[1][1] - a[0][1] * a[1][0];

	else
	{
		int i, j, k, f1 = 0, f2 = 0;
		for (i = 0; i < b; i++)
		{
			for (j = 1; j < b; j++)
			{
				for (k = 0; k < b; k++)
				{
					if (k == i)
						continue;
					mat[f1][f2] = a[j][k];
					f2++;
				}
				f1++;
				f2 = 0;
			}
			d = d + (float)pow(-1, i)*a[0][i]*det(b - 1, mat);

			f1 = 0;
		}
	}
	return d;
}

int main()
{
	string  s1;
	//counting rows 
	string n;
	int x = 0, h = 0, counter = 0, l;
	getline(cin, s1);
	l = s1.length();
	s1 = s1.substr(1, (l -= 2));

	while (1)
	{
		n = s1.substr(h);

		x = n.find(";");
		if (x == -1)
			break;
		counter++,
			h += ++x;

	}

	int r1 = ++counter;

	//counting coulmns
	x = s1.find(";");
	string str[100];
	str[1] = s1.substr(0, x);

	//processing
	x = 0, h = 0, counter = 0;
	while (1)
	{
		n = str[1].substr(h);

		x = n.find(" ");
		if (x == -1)
			break;
		counter++,
			h += ++x;

	}

	int c1 = ++counter;
	//counting spaces for ERRORS
	string o;
	x = 0, h = 0, counter = 0;

	while (r1 > 1)
	{
		while (1)
		{
			o = s1.substr(h);

			x = o.find(" ");
			if (x == -1)
				break;
			counter++,
				h += ++x;
		}
		if (counter != (c1 - 1)*r1)
		{
			cout << "ERROR";
			exit(0);
		}
		else break;
	}
	// ERROR 1
	if (c1 > 100 || r1 > 100)
	{
		cout << "ERROR";
		exit(0);
	}
	//project
	float a1[100][100];

	string s[100][100];


	//deep shit
	int i, j, z = 0, y = 0;
	x = 0, h = 0;

	for (i = 0; i < r1; i++)
	{
		x = s1.find(";");
		if (x == -1)
		{
			str[i] = s1.substr(h);
		}
		else
		{
			str[i] = s1.substr(h, (x - h));

			s1 = s1.erase(x, 1);

			h = x;

		}
		for (j = 0; j < c1; j++)
		{
			z = str[i].find(" ");
			if (z == -1)
			{
				s[i][j] = str[i].substr(y);

				a1[i][j] = atof(s[i][j].c_str());
			}
			else
			{
				s[i][j] = str[i].substr(y, (z - y));

				str[i] = str[i].erase(z, 1);

				y = z;

				a1[i][j] = atof(s[i][j].c_str());

			}
		}
		y = 0;

	}
	// Stage 2

	char opt;

	cin >> opt;
	// REPEATITION                                                                      HERE HERE HERE
	float mat[100][100];

	if (opt == '+' || opt == '-' || opt == '*' || opt == '/')
	{
		string s2;
		//counting rows    2
		string n1;
		x = 0, h = 0, counter = 0;
		cin.ignore();
		getline(cin, s2);
		l = s2.length();
		s2 = s2.substr(1, (l -= 2));
		while (1)
		{
			n1 = s2.substr(h);

			x = n1.find(";");
			if (x == -1)
				break;
			counter++,
				h += ++x;

		}

		int r2 = ++counter;

		//counting coulmns   2
		x = s2.find(";");
		for (i = 0; i < r1;i++)
		str[i].clear();
		str[1] = s2.substr(0, x);

		//processing    2
		x = 0, h = 0, counter = 0;
		while (1)
		{
			n1 = str[1].substr(h);

			x = n1.find(" ");
			if (x == -1)
				break;
			counter++,
				h += ++x;

		}

		int c2 = ++counter;
		//counting spaces for ERRORS      2
		string o1;
		x = 0, h = 0, counter = 0;

		while (r2 > 1)
		{
			while (1)
			{
				o1 = s2.substr(h);

				x = o1.find(" ");
				if (x == -1)
					break;
				counter++,
					h += ++x;
			}
			if (counter != (c2 - 1)*r2)
			{
				cout << "ERROR";
				exit(0);
			}
			else break;
		}
		// ERROR 1       2
		if (c2 > 100 || r2 > 100)
		{
			cout << "ERROR";
			exit(0);
		}
		//project    2
		float a2[100][100];

		string st[100][100];


		//deep shit
		i = 0, j = 0, z = 0, y = 0;
		x = 0, h = 0;

		for (i = 0; i < r2; i++)
		{
			x = s2.find(";");
			if (x == -1)
			{
				str[i] = s2.substr(h);
			}
			else
			{
				str[i] = s2.substr(h, (x - h));

				s2 = s2.erase(x, 1);

				h = x;

			}
			for (j = 0; j < c2; j++)
			{
				z = str[i].find(" ");
				if (z == -1)
				{
					st[i][j] = str[i].substr(y);

					a2[i][j] = atof(st[i][j].c_str());
				}
				else
				{
					st[i][j] = str[i].substr(y, (z - y));

					str[i] = str[i].erase(z, 1);

					y = z;

					a2[i][j] = atof(st[i][j].c_str());
				}
			}
			y = 0;
		}
		// REPEATION OVER                             REPEATION OVER            ERRORS ARE NOT COUNTED
		switch (opt)
		{

		case '+': if (r1 != r2 || c1 != c2)
		{
			cout << "ERROR";
			exit(0);
		}
				  for (i = 0; i < r1; i++)
				  {
					  for (j = 0; j < c1; j++)
					  {
						  mat[i][j] = a1[i][j] + a2[i][j];
					  }
				  }
				  break;

		case '-': if (r1 != r2 || c1 != c2)
		{
			cout << "ERROR";
			exit(0);
		}
				  for (i = 0; i < r1; i++)
				  {
					  for (j = 0; j < c1; j++)
					  {
						  mat[i][j] = a1[i][j] - a2[i][j];
					  }
				  }
				  break;
		case '*': if (c1 != r2)
		{
			cout << "ERROR";
			exit(0);
		}
				  float a[100];
				  int t;
				  for (i = 0; i < r1; i++)
				  {
					  for (j = 0; j < c2; j++)
					  {
						  mat[i][j] = 0;
						  for (t = 0; t < r2; t++)
						  {
							  a[t] = a1[i][t] * a2[t][j];

							  mat[i][j] += a[t];
						  }
					  }
				  }

				  cout << "[";
				  for (i = 0; i < r1; i++)
				  {
					  for (j = 0; j < c2; j++)
					  {
						  cout << mat[i][j];
						  if (j == c2 - 1)
							  continue;
						  cout << " ";
					  }
					  if (i == r1 - 1)
						  continue;
					  cout << ";";
				  }
				  cout << "]";

				  exit(0);
				  // dividing :(                               dividing (REPETITION)
		case '/':
		{
			if (r2 != c2 || c1 != r2)
		{
			cout << "ERROR";
			exit(0);
		}
				 //inverse
			float div[100][100];
			if (r2 == 1)
			{
				div[0][0] = 0;
			}
			else if (r2 == 2)
			{
				div[0][0] = a2[1][1];
				div[1][1] = a2[0][0];
				div[0][1] = a2[0][1] * -1;
				div[1][0] = a2[1][0] * -1;
			}
			else
			{
				float inv[100][100], tra[100][100];
				int  e, k, f1 = 0, f2 = 0;
				for (e = 0; e < r2; e++)
				{
					for (i = 0; i < r2; i++)
					{
						for (j = 0; j < r2; j++)
						{
							if (j == e)
								continue;
							for (k = 0; k < r2; k++)
							{
								if (k == i)
									continue;
								inv[f1][f2] = a2[j][k];
								f2++;
							}
							f1++;
							f2 = 0;
						}
						tra[e][i] = pow(-1, e + i + r2 - 1)*det(r2 - 1, inv);

						f1 = 0;
					}
				}
				//transpose
				for (i = 0; i < r2; i++)
					for (j = 0; j < r2; j++)
						div[i][j] = tra[j][i];
			}
				 //determinant
				 float d;
				 d = det(r2, a2);

				 for (i = 0; i < r2; i++)
					 for (j = 0; j < r2; j++)
						 div[i][j] *= (float) 1.0 / d;
				 //dividing
				 for (i = 0; i < r1; i++)
				 {
					 for (j = 0; j < c2; j++)
					 {
						 mat[i][j] = 0;
						 for (t = 0; t < r2; t++)
						 {
							 a[t] = a1[i][t] * div[t][j];

							 mat[i][j] += a[t];
						 }
					 }
				 }
				 break;
		}
		default:
			cout << "ERROR";
			break;
		}

	}
	//    level 2                                                  level 2
	else if (opt == '^' || opt == 'T' || opt == 'D' || opt == 'I')
	{
		switch (opt)
		{

		case'^': int pw, k1, k2, k;
			if (c1 != r1)
			{
				cout << "ERROR";
				exit(0);
			}
			cin >> pw;
			float a[100];
			float a2[100][100];
			int t;
			for (k1 = 0; k1 < r1; k1++)
				for (k2 = 0; k2 < r1; k2++)
					a2[k1][k2] = a1[k1][k2];


			for (k = 1; k < pw; k++)
			{
				for (i = 0; i < r1; i++)
				{
					for (j = 0; j < c1; j++)
					{
						mat[i][j] = 0;
						for (t = 0; t < r1; t++)
						{
							a[t] = a2[i][t] * a1[t][j];

							mat[i][j] += a[t];
						}
					}
				}
				for (k1 = 0; k1 < r1; k1++)
					for (k2 = 0; k2 < r1; k2++)
						a2[k1][k2] = mat[k1][k2];
			}
			break;
		case 'T':
			for (i = 0; i < c1; i++)
				for (j = 0; j < r1; j++)
					mat[i][j] = a1[j][i];

			cout << "[";
			for (i = 0; i < c1; i++)
			{
				for (j = 0; j < r1; j++)
				{
					cout << mat[i][j];
					if (j == r1 - 1)
						continue;
					cout << " ";
				}
				if (i == c1 - 1)
					continue;
				cout << ";";
			}
			cout << "]";
						
			exit(0);
			// determinant
		case'D': if (r1 != c1)
		{
			cout << "ERROR";
			exit(0);
		}
				 float d;
				 d = det(r1, a1);

				 cout << d;
				 exit(0);
				 // Inverse
		case 'I':
		{
			if (r1 != c1)
			{
				cout << "ERROR";
				exit(0);
			}
			if (r1 == 1)
			{
				mat[0][0] = 0;
				cout << mat[0][0];
			}
			else if (r1 == 2)
			{
				mat[0][0] = a1[1][1];
				mat[1][1] = a1[0][0];
				mat[0][1] = a1[0][1] * -1;
				mat[1][0] = a1[1][0] * -1;
			}
			else
			{
				float inv[100][100], tra[100][100];
				int e, f1 = 0, f2 = 0;
				for (e = 0; e < r1; e++)
				{
					for (i = 0; i < r1; i++)
					{
						for (j = 0; j < r1; j++)
						{
							if (j == e)
								continue;
							for (k = 0; k < r1; k++)
							{
								if (k == i)
									continue;
								inv[f1][f2] = a1[j][k];
								f2++;
							}
							f1++;
							f2 = 0;
						}
							tra[e][i] = pow(-1, e + i)*det(r1 - 1, inv);
						
						f1 = 0;
					}
				}
				for (i = 0; i < r1; i++)
					for (j = 0; j < r1; j++)
						mat[i][j] = tra[j][i];

			}

			d = det(r1, a1);

			for (i = 0; i < r1; i++)
				for (j = 0; j < r1; j++)
					mat[i][j] *= (float) 1.0 / d;
			break;
		}
		default:
			cout << "ERROR";
			break;
		}
		
	}
	else
	{
		cout << "ERROR";
		exit(0);
	}
	cout << "[";
	for (i = 0; i < r1; i++)
	{
		for (j = 0; j < c1; j++)
		{
			cout<< mat[i][j];
			if (j == c1 - 1)
				continue;
			cout<<" ";
		}
		if (i == r1 - 1)
			continue;
		cout << ";";
	}
	cout << "]";




	return 0;

}
