t e m p l a t e   < t y p e n a m e   T >  
 c l a s s   f l o w _ g r a p h   {  
     p u b l i c :  
     s t a t i c   c o n s t e x p r   T   e p s   =   ( T )   1 e - 9 ;  
  
     s t r u c t   e d g e   {  
         i n t   t o ;  
         T   c ;  
         T   f ;  
         i n t   r e v ;  
     } ;  
  
     v e c t o r <   v e c t o r < e d g e >   >   g ;  
     v e c t o r < i n t >   p t r ;  
     v e c t o r < i n t >   d ;  
     v e c t o r < i n t >   q ;  
     i n t   n ;  
     i n t   s t ,   f i n ;  
     T   f l o w ;  
        
     f l o w _ g r a p h ( i n t   _ n ,   i n t   _ s t ,   i n t   _ f i n )   :   n ( _ n ) ,   s t ( _ s t ) ,   f i n ( _ f i n )   {  
         a s s e r t ( 0   < =   s t   & &   s t   <   n   & &   0   < =   f i n   & &   f i n   <   n   & &   s t   ! =   f i n ) ;  
         g . r e s i z e ( n ) ;  
         p t r . r e s i z e ( n ) ;  
         d . r e s i z e ( n ) ;  
         q . r e s i z e ( n ) ;  
         f l o w   =   0 ;  
     }  
  
     v o i d   c l e a r _ f l o w ( )   {  
         f o r   ( i n t   i   =   0 ;   i   <   n ;   i + + )   {  
             f o r   ( e d g e   & e   :   g [ i ] )   {  
                 e . f   =   0 ;  
             }  
         }  
         f l o w   =   0 ;  
     }  
        
     v o i d   a d d ( i n t   f r o m ,   i n t   t o ,   T   f o r w a r d _ c a p ,   T   b a c k w a r d _ c a p )   {  
         a s s e r t ( 0   < =   f r o m   & &   f r o m   <   n   & &   0   < =   t o   & &   t o   <   n ) ;  
         i n t   f r o m _ s i z e   =   g [ f r o m ] . s i z e ( ) ;  
         i n t   t o _ s i z e   =   g [ t o ] . s i z e ( ) ;  
         g [ f r o m ] . p u s h _ b a c k ( { t o ,   f o r w a r d _ c a p ,   0 ,   t o _ s i z e } ) ;  
         g [ t o ] . p u s h _ b a c k ( { f r o m ,   b a c k w a r d _ c a p ,   0 ,   f r o m _ s i z e } ) ;  
     }  
  
     b o o l   e x p a t h ( )   {  
         f i l l ( d . b e g i n ( ) ,   d . e n d ( ) ,   - 1 ) ;  
         q [ 0 ]   =   f i n ;  
         d [ f i n ]   =   0 ;  
         i n t   b e g   =   0 ,   e n d   =   1 ;  
         w h i l e   ( b e g   <   e n d )   {  
             i n t   i   =   q [ b e g + + ] ;  
             f o r   ( c o n s t   e d g e   & e   :   g [ i ] )   {  
                 c o n s t   e d g e   & b a c k   =   g [ e . t o ] [ e . r e v ] ;  
                 i f   ( b a c k . c   -   b a c k . f   >   e p s   & &   d [ e . t o ]   = =   - 1 )   {  
                     d [ e . t o ]   =   d [ i ]   +   1 ;  
                     i f   ( e . t o   = =   s t )   {  
                         r e t u r n   t r u e ;  
                     }  
                     q [ e n d + + ]   =   e . t o ;  
                 }  
             }  
         }  
         r e t u r n   f a l s e ;  
     }  
        
     T   d f s ( i n t   v ,   T   w )   {  
         i f   ( v   = =   f i n )   {  
             r e t u r n   w ;  
         }  
         i n t   & j   =   p t r [ v ] ;  
         w h i l e   ( j   > =   0 )   {  
             c o n s t   e d g e   & e   =   g [ v ] [ j ] ;  
             i f   ( e . c   -   e . f   >   e p s   & &   d [ e . t o ]   = =   d [ v ]   -   1 )   {  
                 T   t   =   d f s ( e . t o ,   m i n ( e . c   -   e . f ,   w ) ) ;  
                 i f   ( t   >   e p s )   {  
                     g [ v ] [ j ] . f   + =   t ;  
                     g [ e . t o ] [ e . r e v ] . f   - =   t ;  
                     r e t u r n   t ;  
                 }  
             }  
             j - - ;  
         }  
         r e t u r n   0 ;  
     }  
  
     T   m a x _ f l o w ( )   {  
         w h i l e   ( e x p a t h ( ) )   {  
             f o r   ( i n t   i   =   0 ;   i   <   n ;   i + + )   {  
                 p t r [ i ]   =   ( i n t )   g [ i ] . s i z e ( )   -   1 ;  
             }  
             T   b i g _ a d d   =   0 ;  
             w h i l e   ( t r u e )   {  
                 T   a d d   =   d f s ( s t ,   n u m e r i c _ l i m i t s < T > : : m a x ( ) ) ;  
                 i f   ( a d d   < =   e p s )   {  
                     b r e a k ;  
                 }  
                 b i g _ a d d   + =   a d d ;  
             }  
             i f   ( b i g _ a d d   < =   e p s )   {  
                 b r e a k ;  
             }  
             f l o w   + =   b i g _ a d d ;  
         }  
         r e t u r n   f l o w ;  
     }  
  
     v e c t o r < b o o l >   m i n _ c u t ( )   {  
         m a x _ f l o w ( ) ;  
         v e c t o r < b o o l >   r e t ( n ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   n ;   i + + )   {  
             r e t [ i ]   =   ( d [ i ]   ! =   - 1 ) ;  
         }  
         r e t u r n   r e t ;  
     }  
 } ; 