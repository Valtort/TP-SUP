
(* Code recopier de l'exo 1 *)
let rec taille (l:'a list) : int =
  match l with 
  | [] ->0
  | _ ::q -> 1+ (taille q)

let rec recherche (l:'a list) (x:'a) : bool =
  match l with
  | [] -> false
  | y::q -> if x =y then true
  else recherche (q) (x)

let rec somme (l:int list) : int =
  match l with
  | [] -> 0
  |x::q -> x + somme(q)

let rec concatener (a:'a list) (b:'a list) : ('a list) =
  match (a,b) with
  | [], _ -> b
  | _, [] -> a
  | x::q, y::p -> x::(concatener q b)

let rec multi_concat (l:'a list list) : ('a list) =
  match l with 
  | [] -> []
  | x::q -> concatener x (multi_concat q)

let compose_aux (f:'a -> 'b) (g:'c -> 'a ) (x:'c) = f (g x)

let compose (f:'a->'b) (g:'c -> 'a) = compose_aux f g

(* renvoie la concaténation de toutes les cahines de caractèrse de la liste donnée *)
let rec string_cat (l:string list) : string =
  match l with
  | [] -> ""
  | x::q -> x^(string_cat q)

(* Fonction fold qu'on nous demande de recopier *)
let rec fold (f:'a -> 'b -> 'b) (l:'a list) (a:'b) : 'b =
  match l with
  | [] -> a
  | x::q -> f x (fold f q a)

(* Fonction somme mais implémenter avec fold *)
let new_somme (l:int list) : int = fold (+) l 0

(* Fonction recherche mais avec fold *)
let new_recherche (l:'a list) (x:'a) :bool  = fold (fun y q -> if x=y then true else q) l false

(* Fonction multi_concat mais avec fold *)
let new_multi_concat (l:'a list list) :'a list = fold concatener l []

(* Fonction compose_liste mais avec fold *)
let new_compose_list (l:('a->'a) list) : 'a -> 'a = 
  fold compose l (fun x -> x)

(* Prend en entrée une liste L, une fonction f et renvoie la liste obtenue en appliquant
f à chaque élément de L *)
let rec map (f: 'a -> 'b) (l: 'a list) : ('b list ) =
  match l with 
  | [] -> []
  | x::q -> f(x)::(map f q)

(* Prend en entrée une liste et une fonction de filtre et renvoie la 
liste des éléments qui passent le filtre *)
let rec filter (l:'a list) (f : 'a -> bool) : 'a list =
  match l with
  | [] -> []
  | x::q -> if f x then x:: (filter q f ) else filter q f

let new_map (f: 'a -> 'b) (l: 'a list) : ('b list ) = fold (fun x l -> (f x)::l) l []

let new_filter (l:'a list) (f : 'a -> bool) : 'a list = fold (fun x l -> if f x then x::l else l) l []

(* Transforme une liste de caractère en string *)
let string_of_list (l:char list) : string =
  String.of_seq (List.to_seq l)

(* Divise un string en mots selon un caractère de séparation *)
let rec split_from_i (s: string) (sep: char) (i: int) (curr: char list) : string list =
  if i = String.length s then 
    (* curr est stockée à l'envers, il faut la renverser *)
    [string_of_list (List.rev curr)]
  else if s.[i] = sep then (* on a fini de lire un segment *)
    string_of_list (List.rev curr) :: split_from_i s sep (i+1) []
  else (* on rajoute la lettre au segment actuel *)
      split_from_i s sep (i+1) (s.[i] :: curr)

let split (s:string) (sep:char) : string list =
  split_from_i s sep 0 []

let test () =
  assert(string_cat ["Salut "; "j'aime "; "Ocaml"] = "Salut j'aime Ocaml");
  assert(new_somme [1;2;3;4] = 10);
  assert(new_recherche [1;2;3;4] 1 = true);
  assert(new_recherche [1;2;3;4] 5 = false);
  assert(new_multi_concat [[1;2];[3;4;5];[6;7]] = [1;2;3;4;5;6;7]);
  assert(new_compose_list [(fun x->x*x);(fun x->x+1); (fun x -> 2)] 99 = 9);
  assert(new_compose_list [(fun x->0);(fun x->x+1); (fun x -> 2)] 99 = 0);
  assert(filter [1;2;3;4;5;6;7;8] (fun x -> (x mod 2 = 0)) = [2;4;6;8]);
  assert(new_map (fun x -> x*x) [2;3;4] = [4;9;16]);
  assert(new_filter [1;2;3;4;5;6;7;8] (fun x -> (x mod 2 = 0)) = [2;4;6;8]);
  assert(split "toto,tata,tutu" ','  = ["toto"; "tata"; "tutu"]);
  print_string "Tous les tests ont réussi !\n"