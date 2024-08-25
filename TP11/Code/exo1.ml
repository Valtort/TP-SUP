
(* Renvoie la somme d'une liste d'entiers *)
let rec somme (l:int list) : int =
  match l with
  | [] -> 0
  |x::q -> x + somme(q)

(* Prend une liste L, un élément x, détermine si x est dans L *)
let rec recherche (l:'a list) (x:'a) : bool =
  match l with
  | [] -> false
  | y::q -> if x =y then true
  else recherche (q) (x)

(* Concatene deux listes a et b *)
let rec concatener (a:'a list) (b:'a list) : ('a list) =
  match (a,b) with
  | [], _ -> b
  | _, [] -> a
  | x::q, y::p -> x::(concatener q b)

(* Concatene une liste de liste *)
let rec multi_concat (l:'a list list) : ('a list) =
  match l with 
  | [] -> []
  | x::q -> concatener x (multi_concat q)

(* Prend en entrée une liste L, une fonction f et renvoie la liste obtenue en appliquant
f à chaque élément de L *)
let rec map (f: 'a -> 'b) (l: 'a list) : ('b list ) =
  match l with 
  | [] -> []
  | x::q -> f(x)::(map f q)

(* Fonction auxiliaire ayant pour but de coder reverse(qui renverse une liste) *)
let rec rev_concat (q:'a list) (p: 'a list) : ('a list) =
  match q with 
  | [] -> p 
  | x::l -> rev_concat l (x::p)

(* Fonction reverse *)
let reverse (l: 'a list) : ('a list) = rev_concat l []

(* Fonction auxiliaire pour la fonction range (qui prend en entrée un entier n 
et renvoie [0;1;...;n-1]) *)
let rec range_aux (n:int) (acc:int list): (int list) =
  match n with
  | 0 -> acc
  | _ -> if n<0 then failwith"Il faut mettre un entier positif !"
  else (range_aux (n-1) ((n-1)::acc))

let range (n:int) : (int list) = range_aux n []

(* Prend en entrée une fonction f et un entier n et renvoie [f(0); f(1); ...; f(n-1)] *)
let make_list (f:int -> 'a) (n:int) : ('a list) = map f (range n)

(* Fonction auxiliare qui permet de coder "compose", qui compose f et g en f rond g *)
let compose_aux (f:'a -> 'b) (g:'c -> 'a ) (x:'c) = f (g x)

let compose (f:'a->'b) (g:'c -> 'a) = compose_aux f g


(* Fonction compose_liste, prend en entrée une liste de fonction et les composes toutes entre elles *)
let rec compose_liste_aux (l:('a -> 'a) list) (acc:'a -> 'a) (x:'a) : 'a =
  match l with 
  | [] -> acc x 
  | y::q -> (compose_liste_aux (q) (compose y acc)) x

let compose_liste (l: ('a->'a) list) : 'a -> 'a = compose_liste_aux (reverse l) (fun x->x)

(* Code de la fonction fk: x -> x/(2+k) si x est pair, 3x + k sinon *)
let fk (k:int) (x:int) : int =
  if x mod (2+k) = 0 then x/(2+k) else 3*x+k

(* Code de la fonction Fn = f0 rond f1 rond ... rond fn-1 *)
let fn (n:int) : int -> int = 
  compose_liste (make_list fk n)

(* Finalement, voici le code de F = Fn(0) + ... + Fn(n-1) *)
let f (n:int) : int = somme( make_list (fn n) n)

let test () = 
  assert(somme [1;2;3;4;5;10] = 25);
  assert(recherche [1;2;3;4;5;10] 1 = true);
  assert(recherche [1;2;3;4;5;10] 100 = false);
  assert(concatener [1;2;3] [4;5;6] = [1;2;3;4;5;6]);
  assert(multi_concat [[1;2];[3;4;5];[6;7]] = [1;2;3;4;5;6;7]);
  assert(map (fun x -> x*x) [2;3;4] = [4;9;16]);
  assert(reverse [2;3;4] = [4;3;2]);
  assert(range 5 = [0;1;2;3;4]);
  assert(make_list (fun x -> x*x) 5 = [0;1;4;9;16]);
  assert(compose_liste [(fun x->x*x);(fun x->x+1); (fun x -> 2)] 99 = 9);
  assert(compose_liste [(fun x->0);(fun x->x+1); (fun x -> 2)] 99 = 0);
  assert(f 3 = 83);
  assert(f 20 = 60321545051);
  assert(f 30 = 12254504478085045);
  print_string "Tous les tests ont réussi !\n"