(* Début des fonctions et types importé depuis l'archive du prof *)
type couleur = Coeur | Carreau | Pique | Trefle ;;

let couleur1 = Pique ;;

let est_rouge c = match c with
	| Coeur   -> true
	| Carreau -> true
	| Pique   -> false
	| Trefle  -> false ;;

assert (est_rouge Carreau);; (* vaut true *)

type carte = 
	| Nombre of (int * couleur) (* Cartes 2 à 10 *)
	| Valet of couleur
	| Dame of couleur
	| Roi of couleur
	| As of couleur

let carte_1 = Valet Coeur
let carte_2 = Nombre (9, Pique)

(* Renvoie la couleur d'une carte *)
let couleur_de_carte ca = match ca with
	| Nombre (_, c)  | Valet c 
	| Dame c | Roi c | As c -> c 
;;

assert (couleur_de_carte (Roi Trefle) = Trefle) ;;

(* Fin des fonctions et types importé depuis l'archive du prof *)

(* Transforme une couleur en chaîne de caractère *)
let string_of_couleur (c:couleur) : string =
  match c with
  | Pique -> "Pique"
  | Coeur -> "Coeur"
  | Carreau -> "Carreau"
  | Trefle -> "Trefle"

(* Transforme une carte en chaîne de caractère *)
let string_of_carte (ca:carte) : string =
  match ca with 
  | Nombre (x, c) -> if (x>=2 && x<=10) then (string_of_int x)^" de "^(string_of_couleur c)
  else failwith"Nombre non compris entre 2 et 10, cartes non valide !"
  | Valet c -> "Valet de "^(string_of_couleur c)
  | Dame c -> "Dame de "^(string_of_couleur c)
  | Roi c -> "Roi de "^(string_of_couleur c)
  | As c -> "As de "^(string_of_couleur c)

(* Compare deux cartes selon l'ordre suivant, coeurs < carreaux < piques < trèfles 
Au sein d'une même couleur on respecte l'ordre 2<3<...<Roi<As
Renvoie -1 0 ou 1 selon si la première carte est inférieur, égale ou supérieure à la seconde*)
let cmp (c1:carte) (c2:carte) : int =
  if (c1 = c2) then 0 
  else let couleur1 = couleur_de_carte c1 in let couleur2 = couleur_de_carte c2 in
  if (couleur1 = couleur2) then 
    if c1<c2 then -1 else 1
  else if (couleur1 < couleur2) then -1
  else 1
(* Rem : On utilise l'ordre natif d'Ocaml *)


(* insére une carte au bon endroit dans une main supposée triée (une main est une liste de cartes) *)
let rec insert_aux (c:carte) (l:carte list) (acc: carte list) : carte list =
  match l with 
  | [] -> List.rev(c::acc)
  | x::q -> if (cmp c x) <= 0 then (List.rev acc)@(c::x::q)
  else insert_aux c q (x::acc)

let insert (c:carte) (l:carte list) : carte list = insert_aux c l []

(* Tri par insertion d'une main *)
let rec insert_sort_aux (l:carte list) (acc : carte list): carte list = 
  match l with 
  | [] -> acc
  | x::q -> insert_sort_aux q (insert x acc)

let insert_sort (l:carte list): carte list = insert_sort_aux l []

(* Genere la liste des 13 cartes de la couleur c donné *)
let rec gen_couleur_aux (c:couleur) (n:int) : carte list =
  match n with
  | 0 -> []
  | _ -> if (n = 1) then (As c)::(gen_couleur_aux c (n-1))
  else if (n = 11) then (Valet c)::(gen_couleur_aux c (n-1))
  else if (n = 12) then (Dame c)::(gen_couleur_aux c (n-1))
  else if (n = 13) then (Roi c)::(gen_couleur_aux c (n-1))
  else (Nombre (n, c))::(gen_couleur_aux c (n-1))

let gen_couleur_aux (c:couleur) : carte list = List.rev(gen_couleur_aux c 13)

(* Fonction de tests *)
let test () = 
  assert(string_of_carte carte_1 = "Valet de Coeur");
  assert(string_of_carte carte_2 = "9 de Pique");
  assert(cmp (Nombre (1,Coeur)) (Nombre (1,Carreau)) = -1);
  assert(cmp (Nombre (1,Pique)) (Nombre (1,Carreau)) = 1);
  assert(cmp (Nombre (1,Coeur)) (Nombre (2,Coeur)) = -1);
  assert(cmp (Nombre (3,Coeur)) (Nombre (2,Coeur)) = 1);
  assert(cmp (Nombre (3,Coeur)) (Nombre (3,Coeur)) = 0);
  assert(cmp (As Trefle) (Roi Trefle) = 1);
  assert(insert (Roi Trefle) [(Valet Trefle);(Dame Trefle);(As Trefle)] = [Valet Trefle; Dame Trefle; Roi Trefle; As Trefle]);
  assert(insert (Dame Pique) [(Valet Coeur);(Dame Carreau);(As Trefle)] = [Valet Coeur; Dame Carreau; Dame Pique; As Trefle]);
  assert(insert_sort [(Valet Trefle);(Dame Carreau);(As Coeur); (As Trefle)]= [As Coeur; Dame Carreau; Valet Trefle; As Trefle]);
  assert( gen_couleur_aux Trefle = [As Trefle; Nombre (2, Trefle); Nombre (3, Trefle); Nombre (4, Trefle);
  Nombre (5, Trefle); Nombre (6, Trefle); Nombre (7, Trefle);
  Nombre (8, Trefle); Nombre (9, Trefle); Nombre (10, Trefle); Valet Trefle;
  Dame Trefle; Roi Trefle]);
  print_string"Tout les tests ont réussi !\n";;