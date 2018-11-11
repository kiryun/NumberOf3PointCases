# NumberOf3PointCases

## Example


input
\
\* \* \# * * \n
\* \* \# * * \n
\* \* \# * * \n

r -> ** \n
     * \n
     
R -> ** \n
      * \n
      
L -> *
     **
     
J -> **
      *


r r \# r r
r J \# r J
J J \# J J

--> +1

r r \# R R
r J \# L R
J J \# L L

--> +2

R R \# R R
L R \# L R
L L \# L L

--> +3

R R \# r r
L R \# r J
L L \# J J

--> +4

output
4
