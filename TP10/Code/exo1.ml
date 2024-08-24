(* Renvoie le double d'un entier a *)
let double (a: int): int = a*2

(* Renvoie le premier paramètre donné *)
let first (a,b:float*float) = a

(* Renvoie le second paramètre donné *)
let second (a,b:float*float) = b

(* Ajouter les trois flottants a b c *)
let ajouter (a,b,c:float*float*float) : float = a+.b+.c

(* Determine si un entier est pair *)
let est_pair (a:int) : bool = 
  match a mod 2 with
  | 0 -> true
  | 1 -> false
  | _ -> failwith"N'est pas censé arrivé"

(* Determine si sa première entrée est un diviseur du deuxième *)
let divise (a:int) (b:int) : bool =
  match b mod a with
  | 0 -> true
  | _ -> false

(* fonction telle que ajouteur k est une fonction qui ajoute k a son entrée *)
let ajouteur (a:int) (b:int) : int = a+ b

(* Prend une fonction f et un element x et determine si f(x)=0 *)
let est_racine (f: 'a -> int) (x:'a) : bool =
  match f x with
  | 0 -> true
  | _ -> false

(* Fonction identité *)
let id (a:'a) : 'a = a

(* Prend en entrée deux fonctions f et g et les compose en f rond g*)
let compose_aux (f: 'a -> 'b) (g: 'c -> 'a) (x: 'c) : 'b = f (g x)

let compose (f: 'a->'b) (g: 'c -> 'a) : ('c -> 'b) = compose_aux f g