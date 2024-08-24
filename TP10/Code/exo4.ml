(* calcule de manière naïve la puissance d'un entier par un autre *)
let rec puiss (a:int) (b:int) : int =
  match (a,b) with 
  | _,0 -> 1
  | 0,_ -> 0
  | _ -> a*(puiss a (b-1))


(* Calcule le reste de la division euclidienne d'un entier a par un autre b sans utilise mod *)
(* On supp a>=0 et b>0 *)
let rec reste (a:int ) (b:int) : int =
  match (a,b) with
  | 0,_ -> 0
  | _,_ -> if a<b then a (* dans ce cas la, on ne peut plus diviser*)
  else reste (a-b) b

(* calcule le pgcd de deux entiers avec l'algo d'Euclide *)
let rec pgcd (a:int) (b:int) : int =
  if b = 0 then a 
  else if a = 0 then b 
  else 
  let x = a mod b in
  let y = a in pgcd x y

(* Calcule de la puissance d'un entier par un autre de manière rapide *)
let rec puiss_rapide (a:int) (b:int) : int =
  if b = 1 then a 
  else if (b mod 2 =0) then (puiss_rapide (a*a) (b/2))
  else a* (puiss_rapide (a*a) ((b-1)/2))

(* Calcule le couple (quotient, reste) de la div euclidienne d'un entier a par un autre b
Sans utiliser / et mod *)
(* On supp a>=0 b>0 *)
let rec div_eucl_aux (a:int) (b:int) (acc:int): (int*int) =
  match (a,b) with
  | 0,_ -> (acc,0)
  | _,_ -> if a<b then (acc,a)
  else div_eucl_aux (a-b) b (acc+1)

let div_eucl (a:int) (b:int) = div_eucl_aux a b 0

(* On reprend cette fonction de l'exo 1 *)
let est_racine (f: int -> 'a) (x: int) : bool =
  match f x with
  | 0 -> true
  | _ -> false


(* Prend en entrée, une fonction int->int et deux entiers a et b, indique si f admet une racine
dans [a,b] *)
let rec a_racine (f:int->int) (a:int) (b:int) : bool =
  if a<b then (est_racine f a ) || (a_racine f (a+1) b)
  else if a=b then est_racine f b
  else false
