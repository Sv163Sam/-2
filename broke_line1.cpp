//#include "broke_line.h" 
//#include "cmath"
//#include "exception.cpp"

/*point::point()
    {
        _x=0;_y=0;
    }
point::point(double x, double y)
{
    _x=x;
    _y=y;
}

broken_line::broken_line(): _p(NULL), _size(0) {} 

broken_line::broken_line(const unsigned int size) 
{ 
   _size = size; 
   _p = new point[_size]; 
   for (int i = 0; i < _size; i++) 
   {
       std::cout << "Please enter a value of x, y \n";
       std::cin >> _p[i]._x;
       std::cin >> _p[i]._y;
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

broken_line::broken_line(const broken_line& line) 
{ 
   _size = line._size; 
   _p = new point[_size]; 
   for (unsigned int i = 0; i < _size; i++)
    { 
       _p[i] = line._p[i]; 
    } 
} 

void broken_line::swap(broken_line& rhs) 
{ 
   std::swap(_size, rhs._size); 
   std::swap(_p, rhs._p); 
} 

point& broken_line::operator[](const unsigned int index) 
{ 
   if (_size <= index || index < 0) throw invalid_index();
   return _p[index]; 
} 

point broken_line::operator[](const unsigned int index) const 
{ 
   if (_size <= index || index < 0) throw invalid_index();
   return _p[index]; 
} 
broken_line& broken_line::operator= (const broken_line& obj)
{
    if (_size <= 0) throw invalid_index();
    this->_size = obj._size;
    for (unsigned int i = 0; i < obj._size; i++) 
    {
        this->_p[i] = obj._p[i]; 
    }
    return *this;
}

int broken_line::quantity() const
{
    if (_size <= 0) throw invalid_index();
    return _size;
}

bool broken_line::insert_point(const point& p, bool value)
{
    for (int i = 0; i < _size; i++)
    {
       if (p._x == _p[i]._x && p._y == _p[i]._y) throw equal_points();
    }
    point* temp = new point[_size];
    for (unsigned int i = 0; i < _size; i++) 
    {
        temp[i] = _p[i];
    }
    _p = new point[_size + 1]; 
    _size++;
    if (value == true)
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
            _p[i+1] = temp[i];
        }
        _p[_size-1]._x = p._x;
        _p[_size-1]._y = p._y;
    }
    delete[] temp;
}

broken_line& broken_line::operator+=(const point& point) 
{
    int value = 0;
    std::cout << "Please enter 0 - if you want to insert a point to start, 1 - if to end" << std::endl;
    std::cin >> value;
    if (value == 0)
    insert_point(point, true);
    else insert_point(point, false);
    return *this;
}
broken_line broken_line::operator+(const point& point) const
{
    broken_line clone(*this);
    clone += point;
    return clone;
}
broken_line& broken_line::operator+=(const broken_line& line_s)
{
    if (*this == line_s) throw equal_lines();
    for (int i = 0; i < line_s._size; i++)
    {
        insert_point(line_s._p[i], false);
    }
    return *this;
}
broken_line broken_line::operator+(const broken_line& line_s) const
{
    broken_line clone(*this);
    clone += line_s;
    return clone;
}

broken_line::~broken_line() 
{ 
   delete[] _p; 
} 
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

double broken_line::len(const broken_line& line)
    {
        double sum=0;
        if (line._size == 1)
        {
            return sum;
        }
        for (int i = 0; i < line._size - 1; i++)
        {
            
            sum += sqrt(pow((line._p[i + 1]._x - line._p[i]._x), 2) + pow((line._p[i + 1]._y - line._p[i]._y), 2));
        }
        return sum;
    }

bool broken_line::operator > (const broken_line& a)
    {
        if (len(*this) <= len(a))
        {
            return false;
        }
        else return true;
    }
bool broken_line::operator < (const broken_line& a)
    {
        if (len(*this) >= len(a))
        {
            return false;
        }
        else return true;
    }
bool broken_line::operator == (const broken_line& a)
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
*/