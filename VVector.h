#pragma once

template<class T>
class RareVVector;

template<class T>
class VVector
{
public:
	VVector(){}
	VVector(int dim);
	VVector(T *t, int dim);
	VVector(const VVector&);
    ~VVector();

	VVector operator+(const VVector&);
	VVector operator-(const VVector&);
	double operator*(const VVector&);
	double operator~();
	double operator%(const VVector&);
	T      operator[](int) const;
	operator RareVVector<T>();

private:
	T*  m_t;
	int m_dim;
};


// Constructor with one parameter
template<class T>
VVector<T>::VVector(int dim)
{
	m_dim = dim;
	m_t = new T[dim];

	for (int i = 0; i < dim; i++)
		m_t[i] = 1;
}

// Constructor with two parameters
template<class T>
VVector<T>::VVector(T *t, int dim)
{
	m_dim = dim;
	m_t = new T[dim];

	for (int i = 0; i < dim; i++)
		m_t[i] = t[i];
}

// Copy constructor
template<class T>
VVector<T>::VVector(const VVector&v)
{
	m_t = new T[v.m_dim];

	for (int i = 0; i < v.m_dim; i++)
	{
		m_t[i] = v.m_t[i];
	}
	m_dim = v.m_dim;
}

// Freeing up memory
template<class T>
VVector<T>::~VVector()
{
	delete[] m_t;
}

// Addition
template<class T>
VVector<T> VVector<T>::operator+(const VVector&v)
{	
	if (v.m_dim != m_dim)
		throw "Can't perform (+) addition; sizes of the vectors do not match.";

	VVector<T>aux(m_dim);

	for (int i = 0; i < m_dim; i++)
		aux.m_t[i] = m_t[i] + v.m_t[i];

	aux.m_dim = v.m_dim;
	
	return aux;
}

// Subtraction
template<class T>
VVector<T> VVector<T>::operator-(const VVector& v)
{
	if (v.m_dim != m_dim)
		throw "Can't perform (-) subtraction; sizes of the vectors do not match.";
	
	VVector<T>aux(m_dim);

	for (int i = 0; i < m_dim; i++)
		aux.m_t[i] = m_t[i] - v.m_t[i];
	
	aux.m_dim = v.m_dim;
	return aux;
}

// Scalar product
template<class T>
double VVector<T>::operator*(const VVector& v)
{	
	double aux=0;
	if (v.m_dim != m_dim)
		throw "Can't perform (*) scalar product; sizes of the vectors do not match.";

	for (int i = 0; i < m_dim; i++)
		aux += double(m_t[i] * v.m_t[i]);
	return aux;
}

// Euclidean norm
template <class T>
double VVector<T>::operator~()
{
	double aux = 0, root = 1;
	for (int i = 0; i < m_dim; i++)
		aux += double(m_t[i] * m_t[i]);

	for (int i = 0; i < aux; i++)
		root = (root + aux / root) / 2;

	return root;
}

// Euclidean distance
template <class T>
double VVector<T>::operator%(const VVector&v)
{
	if (v.m_dim != m_dim)
		throw "Can't determine (%) euclidean distance; sizes of the vectors do not match.";

	double aux=0, t, root=1;

	for (int i = 0; i < m_dim; i++)
	{	
		t = double(m_t[i] - v.m_t[i]);
		aux += t * t;
	}
	for (int i = 0; i < aux; i++)
		root = (root + aux / root) / 2;

	return root;
}

// Returns the element on the given index
template <class T>
T VVector<T>::operator[](int i) const
{
	if (i < 0)
		throw "The given [] index is smaller than zero; can't return a value";
	if (i > m_dim - 1)
		throw "The given [] index is higher than the vector's size; can't return a value";

	return m_t[i];
}

// Type conversion
template <class T>
VVector<T>::operator RareVVector<T>()
{
	T* aux = new T[m_dim];
	 
	for (int i = 0; i < m_dim; i++)
	{
		aux[i] = m_t[i];
	}
	RareVVector<T> aux2(aux, m_dim);
	return aux2;
}

