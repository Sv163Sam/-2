#pragma once 
#include <iostream> 
#include <utility> 
#include "exception.cpp"
#include "cmath"
#include "complex"

template<typename A>
struct point 
{ 
  A _x, _y; 
  point<A>()
  {
    _x=0.0;_y=0.0;
  }
  point<A>(A x, A y)
  {
    _x=x;
    _y=y;
  }
}; 

template<typename T>
class broken_line 
{ 
private: 
    point<T>* _p; 
    unsigned _size; 
public: 
    /*broken_line(); 
    broken_line(point<T> var, const unsigned int size); 
    broken_line(const broken_line<T>& rhs);     
    point<T>& operator[](const unsigned int index); 
    point<T> operator[](const unsigned int index) const; 
    broken_line& operator= (const broken_line<T>& obj); 
    
    bool insert_point(const point<T>& point, bool value);

    broken_line operator+(const broken_line<T>& line_s) const; 
    broken_line operator+(const point<T>& point) const;    
    
    broken_line& operator+=(const broken_line<T>& line_s);  
    broken_line& operator+=(const point<T>& point);   
    
    ~broken_line();    

    double len(const broken_line<T>& line);
    //int quantity() const;

    bool operator > (const broken_line<T>& a);
    bool operator < (const broken_line<T>& a);
    bool operator == (const broken_line<T>& a);*/



    broken_line(): _p(NULL), _size(0) {} 

    broken_line<T>(const unsigned int size, int select_var) 
    { 
        _size = size; 
        _p = new point<T>[_size];   
        for (int i = 0; i < _size; i++)
        {   
            std::cout << "Please enter a value of x, y \n";
            std::cin >> _p[i]._x;
            std::cin >> _p[i]._y;
            if (select_var == 1)
            {
                _p[i]._x = (int)_p[i]._x;
                _p[i]._y = (int)_p[i]._y;
            }
            if (select_var == 2)
            {
                _p[i]._x = (double)_p[i]._x;
                _p[i]._y = (double)_p[i]._y;
            }
            if (select_var == 3)
            {
                std::complex<double> c_point((double)_p[i]._x, (double)_p[i]._y);
                _p[i]._x = c_point.real();
                _p[i]._y = c_point.imag();
            } 
        if (i > 1)
        {
            for (int j = 0; j < i; j++)
            {
            if (_p[i]._x == _p[j]._x && _p[i]._y == _p[j]._y) throw equal_points();
            }
        }
        if (_p[i]._x == (-0)) _p[i]._x = 0;
        if (_p[i]._y == (-0)) _p[i]._y = 0;    
    } 
    }

    broken_line(const broken_line<T>& line) 
    { 
       _size = line._size; 
       _p = new point<T>[_size]; 
       for (unsigned int i = 0; i < _size; i++)
        { 
           _p[i] = line._p[i]; 
        } 
    } 

    point<T>& operator[](const unsigned int index) 
    { 
       if (_size <= index || index < 0) throw invalid_index();
       return _p[index]; 
    } 

    point<T> operator[](const unsigned int index) const 
    { 
       if (_size <= index || index < 0) throw invalid_index();
       return _p[index]; 
    } 
    broken_line<T>& operator= (const broken_line<T>& obj)
    {
        if (_size <= 0) throw invalid_index();
        this->_size = obj._size;
        for (unsigned int i = 0; i < obj._size; i++) 
        {
            this->_p[i] = obj._p[i]; 
        }
        return *this;
    }

    int quantity() const
    {
        if (_size <= 0) throw invalid_index();
        return _size;
    }

    void insert_point_to_start(const point<T>& point)
    {
    int point_to_start = 0;
    insert_point(point, point_to_start);
    }   

    void insert_point(const point<T>& p, int value)
    {
    for (int i = 0; i < _size; i++)
    {
       if (p._x == _p[i]._x && p._y == _p[i]._y) throw equal_points();
    }
    point<T>* temp = new point<T>[_size];
    _size++;
    for (unsigned int i = 0; i < _size-1; i++) 
    {
        temp[i] = _p[i];
    }
    delete[] _p;
    _p = new point<T>[_size]; 
    if (value == 0)
    {
        for (unsigned int i = 0; i < _size-1; i++) 
        {
            _p[i+1] = temp[i];
        }
        _p[0]._x = p._x;
        _p[0]._y = p._y;
    }
    else 
    {
        for (unsigned int i = 0; i < _size; i++) 
        {
            _p[i] = temp[i];
        }
        _p[_size-1]._x = p._x;
        _p[_size-1]._y = p._y;
    }
    delete[] temp;
    }

    broken_line<T>& operator+=(const point<T>& point) 
    {
        int point_to_end = 1;
        insert_point(point, point_to_end);
        return *this;
    }
    
    broken_line<T>& operator+=(const broken_line<T>& line_s)
    {
        if (*this == line_s) throw equal_lines();
        for (int i = 0; i < line_s._size; i++)
        {
            insert_point(line_s._p[i], 1);
        }
        return *this;
    }
    broken_line<T> operator+(const broken_line<T>& line_s) const
    {
        broken_line clone(*this);
        clone += line_s;
        return clone;
    }

    ~broken_line() 
    { 
       delete[] _p; 
    } 

    int distance(const ::point<int>& point, const ::point<int>& point1)
    {
        return sqrt(pow((point1._x - point._x), 2) + pow((point1._y - point._y), 2));
    }
    double distance(const ::point<double>& point, const ::point<double>& point1)
    {
       return sqrt(pow((point1._x - point._x), 2) + pow((point1._y - point._y), 2));
    }
    std::complex<double> distance(const point<std::complex<double> >& point1, const point<std::complex<double> >& point2)
    {
        std::complex<double> z;
        z = sqrt(pow((point2._x - point1._x), 2) + pow((point2._y - point1._y), 2));
        return z;
    }

    T len(const broken_line<T>& line)
    {
        double var = 0;
        if (line._size == 1)
        {
            return var;
        }
        for (int i = 0; i < line._size - 1; i++)
        {
            var += distance(line._p[i], line._p[i + 1]);
        }
        return var;
    }

    bool operator > (const broken_line<T>& a)
        {
            if (len(*this) <= len(a))
            {
                return false;
            }
            else return true;
        }
    bool operator < (const broken_line<T>& a)
        {
            if (len(*this) >= len(a))
            {
                return false;
            }
            else return true;
        }
    bool operator == (const broken_line<T>& a)
        {
            if (len(*this) < len(a) || len(*this) > len(a))
            {
                return false;
            }
            else 
            {
                int count = 0;
                for (unsigned int i = 0; i < _size; i++)
                {
                    if (_p[i]._x == a._p[i]._x && _p[i]._y == a._p[i]._y) count++;
                }
                if (count == _size) return true;
            } 
            return false;
        }

};
template<typename T>
std::istream& operator >> (std::istream& in, point<T>& lhs) 
{ 
   std::cout << "Input x: "; 
   in >> lhs._x; 
   std::cout << "Input y: "; 
   in >> lhs._y; 
   return in; 
} 
template<typename T>
std::ostream& operator << (std::ostream& out ,const point<T>& lhs) 
{ 
    out << "\nx - " << lhs._x; 
    out << "\ny - " << lhs._y; 
    return out; 
} 
template<typename T>
broken_line<T>& operator+(broken_line<T>& obj ,const point<T>& point) 
{
    obj += point;
    return obj;
}
template<typename T>
broken_line<T>& operator+(const point<T>& point, broken_line<T>& obj)
{
    obj.insert_point_to_start(point);
    return obj;
}