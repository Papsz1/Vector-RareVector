#pragma once
#include "VVector.h"

template < class T >
struct nonZero
{
	T elem;
	int index;
};


template<class T>
class RareVVector
{
public:

	operator VVector<T>();
	RareVVector(){}
	RareVVector(int dim);
	RareVVector(T *t, int dim);
	RareVVector(const RareVVector&);
    ~RareVVector();

	RareVVector operator+(const RareVVector&);
	RareVVector operator-(const RareVVector&);
	double operator*(const RareVVector&);
	double operator~();
	double operator%(const RareVVector&);
	T      operator[](int) const;


private:


	nonZero <T> * vvector;
	int nZeroDim;
	int dim;
};

// Constructor with one parameter
template<class T>
RareVVector<T>::RareVVector(int aux_dim)
{
	vvector = new nonZero<T>[aux_dim];
	nZeroDim = 1;
	dim = aux_dim;

	vvector[0].elem = 1;
	vvector[0].index = 0;

	for (int i = 1; i < dim; i++)
	{
		vvector[i].elem = 0;
		vvector[i].index = -1;
	}
}

// Constructor with two parameters
template<class T>
RareVVector<T>::RareVVector(T* t, int aux_dim)
{
	dim = aux_dim;
	nZeroDim = 0;
	vvector = new nonZero<T>[dim];

	for (int i = 0; i < dim; i++)
	{
		if (t[i] != 0)
		{	
			vvector[nZeroDim].elem = t[i];
			vvector[nZeroDim].index = i;
			nZeroDim++;
		}
	}

	for (int i = nZeroDim; i < dim; i++)
	{
			vvector[nZeroDim].elem = 0;
			vvector[nZeroDim].index = -1;
			nZeroDim++;
	}
}

// Copy constructor
template<class T>
RareVVector<T>::RareVVector(const RareVVector&v)
{
	dim = v.dim;
	nZeroDim = v.nZeroDim;
	vvector = new nonZero<T>[dim];

	for (int i = 0; i < nZeroDim; i++)
	{
		vvector[i].elem = v.vvector[i].elem;
		vvector[i].index = v.vvector[i].index;
	}
}

// Freeing up memory
template <class T>
RareVVector<T>::~RareVVector()
{
	delete[] vvector;
}

// Addition
template <class T>
RareVVector<T> RareVVector<T>::operator+(const RareVVector&v)
{
	if ( nZeroDim != v.nZeroDim)
	{
		throw "Can't perform (+) addition; sizes of the vectors do not match.";

	}

	RareVVector<T> aux(dim);

	for (int i = 0; i < nZeroDim; i++)
	{
		if (vvector[i].elem + v.vvector[i].elem != 0)
		{
			aux.vvector[i].elem = (vvector[i].elem + v.vvector[i].elem);
			aux.vvector[i].index = i;
		}
	}

	aux.dim = dim;
	aux.nZeroDim = nZeroDim;

	return (aux);
}

// Subtraction
template <class T>
RareVVector<T> RareVVector<T>::operator-(const RareVVector&v)
{
	if ( nZeroDim != v.nZeroDim)
	{
		throw "Can't perform (-) subtraction; sizes of the vectors do not match.";
	}

	RareVVector<T> aux(dim);

	for (int i = 0; i < nZeroDim; i++)
	{
		if (vvector[i].elem - v.vvector[i].elem != 0)
		{
			aux.vvector[i].elem = (vvector[i].elem - v.vvector[i].elem);
			aux.vvector[i].index = i;
		}
	}

	aux.dim = dim;
	aux.nZeroDim = nZeroDim;

	return (aux);
}

// Scalar product
template <class T>
double RareVVector<T>::operator*(const RareVVector& v)
{
	if ( nZeroDim != v.nZeroDim)
	{
		throw "Can't perform (*) scalar product; sizes of the vectors do not match.";
	}

	double aux=0;

	for (int i = 0; i < nZeroDim; i++)
	{
		aux += (vvector[i].elem * v.vvector[i].elem);
	}
	
	return aux;
}

// Euclidean norm
template <class T>
double RareVVector<T>::operator~()
{
	double aux=0, root=1;

	for (int i = 0; i < nZeroDim; i++)
		aux += double(vvector[i].elem * vvector[i].elem);

	for (int i = 0; i < aux; i++)
		root = (root + aux / root) / 2;

	return root;
}

// Euclidean distance
template <class T>
double RareVVector<T>::operator%(const RareVVector& v)
{
	if (v.nZeroDim != nZeroDim)
		throw "Can't determine (%) euclidean distance; sizes of the vectors do not match.";

	double aux=0, t, root=1;

	for (int i = 0; i < nZeroDim; i++)
	{	
		t = double(vvector[i].elem - v.vvector[i].elem);
		aux += t * t;
	}
	for (int i = 0; i < aux; i++)
		root = (root + aux / root) / 2;

	return root;
}

// Returns the element on the given index
template <class T>
T RareVVector<T>::operator[](int index) const
{
	int ok = 0;

	if (index < 0)
		throw "The given [] index is smaller than zero; can't return a value";

	for (int i = 0; i < nZeroDim; i++)
	{
		if (vvector[i].index == index)
		{
			ok = 1;
			return vvector[i].elem;
		}
	}

	if (ok == 0)
		throw "There is no element on the given index []";
}

// Type conversion
template<class T>
RareVVector<T>::operator VVector<T>()
{
	T* aux = new T[dim];

	for (int i = 0; i < dim; i++)
	{
		aux[i] = 0;
	}

	for (int i = 0; i < dim; i++)
	{	
		if (vvector[i].elem != 0)
			aux[vvector[i].index] = vvector[i].elem;
	}
	
	VVector<T> aux2(aux, dim);

	return aux2;
}
