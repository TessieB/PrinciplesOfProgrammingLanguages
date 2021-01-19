program dt;
uses sysutils;

{Initializes date_t as a record with fields dt_day, dt_month, and dt_year, and declares 
day_range and month_range as subranges}
type
date_t = record
    dt_day: 1..31;
    dt_month: 1..12;
    dt_year: integer;
end;
day_range = 1..31;
month_range = 1..12;
    
    
{Initializes the date with the passed in day, month, and year values}
procedure init_date (var dt : date_t; day : day_range; month : month_range; year : integer);
begin
    dt.dt_day := day;
    dt.dt_month := month;
    dt.dt_year := year;
end;


{Initializes the date with today's current day, month, and year values}
procedure init_date1 (var dt : date_t);
var
    day : word;
    month : word;
    year : word;
begin
    DecodeDate (Date, year, month, day);
    dt.dt_day := day;
    dt.dt_month := month;
    dt.dt_year := year;
end;


{Checks if the two dates passed in are equal and returns true if this is the case}
function date_equal (date1 : date_t; date2 : date_t) : boolean;
begin
    date_equal := false;
    if (date1.dt_day = date2.dt_day) and (date1.dt_month = date2.dt_month) and (date1.dt_year = date2.dt_year) then
        date_equal := true;
end;


{Checks if one date comes before another and returns true if so}
function date_less_than (date1 : date_t; date2 : date_t) : boolean;
begin
    date_less_than := false;
    if (date1.dt_year < date2.dt_year) then
        date_less_than := true
    else if (date1.dt_year = date2.dt_year) and (date1.dt_month < date2.dt_month) then
        date_less_than := true
    else if (date1.dt_year = date2.dt_year) and (date1.dt_month = date2.dt_month)  and (date1.dt_day < date2.dt_day) then
        date_less_than := true;
end;


{Returns the name of the month corresponding to the month integer passed in}
function month_str (month : month_range) : string;
var
    month_names: array [1..12] of string = ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December');
begin
    month_str := month_names[month];
end;


{Formats the date into a string so it reads Month day, year}
procedure format_date (dt : date_t; var ret_str : string);
var
    day_string : string;
    year_string : string;
begin
    str(dt.dt_day, day_string);
    str(dt.dt_year, year_string);
    ret_str := month_str(dt.dt_month) + ' ' + day_string + ', ' + year_string;
end;


{Sets the date equal to the next day}
procedure next_day (var dt : date_t);


    {Returns true if the year is a leap year}
    function leap_year (year : integer) : boolean;
    begin
        leap_year := false;
        if (year mod 4 = 0) then
           leap_year := true;
           if (year mod 100 = 0) then
              leap_year := false;
              if (year mod 400 = 0) then
                 leap_year := true;             
    end;


    {Returns how many days are in the month that is passed in}
    function month_length (month: month_range; leap: boolean): day_range;
    var
        month_num_days : array [1..12] of integer = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
    begin
        if(month = 2) then
            begin
            if (leap_year(dt.dt_year)) then
                month_length := 29
            else
            month_length := 28;
            end
        else
            month_length := month_num_days[month];
    end;


begin
    if (dt.dt_month = 12) and (dt.dt_day = month_length(dt.dt_month, leap_year(dt.dt_year))) then
    begin
        dt.dt_day := 1;
        dt.dt_month := 1;
        dt.dt_year := dt.dt_year + 1;
    end
    else if (dt.dt_day = month_length(dt.dt_month, leap_year(dt.dt_year))) then
    begin
        dt.dt_day := 1;
        dt.dt_month := dt.dt_month + 1;
    end
    else
        dt.dt_day := dt.dt_day + 1;
end;


{Main}
var
    d1, d2, d3 : date_t;
    format_str : string;
begin
    init_date1(d1);
    init_date(d2, 30, 12, 1999);
    init_date(d3, 1, 1, 2000);
   
    format_date(d1, format_str);
    writeln('d1: ' + format_str);
    format_date(d2, format_str);
    writeln('d2: ' + format_str);
    format_date(d3, format_str);
    writeln('d3: ' + format_str);
    
    writeln();
    writeln('d1 < d2? ' , date_less_than(d1, d2));
    writeln('d2 < d3? ' , date_less_than(d2, d3));
    
    writeln();
    next_day(d2);
    format_date(d2, format_str);
    writeln('next day d2: ' + format_str);
    writeln('d2 < d3? ' , date_less_than(d2, d3));
    writeln('d2 = d3? ' , date_equal(d2, d3));
    writeln('d2 > d3? ' , date_less_than(d3, d2));
    
    writeln();
    next_day(d2);
    format_date(d2, format_str);
    writeln('next day d2: ' + format_str);
    writeln('d2 = d3? ' , date_equal(d2, d3));
    
    writeln();
    init_date(d1, 28, 2, 1529);
    format_date(d1, format_str);
    writeln('initialized d1 to ' + format_str);
    next_day(d1);
    format_date(d1, format_str);
    writeln('next day d1: ' + format_str);
    
    writeln();
    init_date(d1, 28, 2, 1460);
    format_date(d1, format_str);
    writeln('initialized d1 to ' + format_str);
    next_day(d1);
    format_date(d1, format_str);
    writeln('next day d1: ' + format_str);
    
    writeln();
    init_date(d1, 28, 2, 1700);
    format_date(d1, format_str);
    writeln('initialized d1 to ' + format_str);
    next_day(d1);
    format_date(d1, format_str);
    writeln('next day d1: ' + format_str);
    
    writeln();
    init_date(d1, 28, 2, 1600);
    format_date(d1, format_str);
    writeln('initialized d1 to ' + format_str);
    next_day(d1);
    format_date(d1, format_str);
    writeln('next day d1: ' + format_str);
end.


