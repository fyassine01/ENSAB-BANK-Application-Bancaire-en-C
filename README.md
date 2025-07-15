# 💳 ENSAB BANK — Application Bancaire en C

Bienvenue dans le projet **ENSAB BANK**, une application bancaire basique codée en **langage C**. Ce projet simule les principales fonctionnalités d’une banque, comme la création de compte, la connexion, le virement et la gestion des soldes.

---

## 🧠 Objectif du Projet

L’objectif de cette application est de permettre :

- La **création de comptes bancaires** avec vérification d’unicité via le CIN.
- La **connexion sécurisée** grâce à l’adresse e-mail et mot de passe.
- La **consultation des informations personnelles** et du solde.
- L’**ajout d’argent** à un compte.
- Le **virement entre comptes** à l’aide du CIN.
- La **gestion de réclamations**.
- L’affichage des **informations générales** sur la banque.

---

## 🛠️ Technologies utilisées

| Langage | Bibliothèques |
|--------|----------------|
| `C`    | `stdio.h`, `stdlib.h`, `string.h`, `conio.h` |

---

## 📁 Fichiers

- `main.c` : Le cœur du programme, contient toutes les fonctions principales.
- `basededonnees.txt` : Fichier binaire contenant les comptes bancaires enregistrés.
- `supp.txt` : Fichier texte utilisé pour enregistrer les ajouts ou retraits de soldes.

---

## ✨ Fonctionnalités principales

### 🔐 Connexion & Authentification
- Vérification d'identité par `EMAIL` et `MOT DE PASSE`.
- Redirection vers le menu bancaire personnel après connexion.

### 👤 Création de compte
- Remplissage des informations personnelles (nom, prénom, CIN, adresse, etc.).
- Vérification que le CIN n’existe pas déjà dans la base de données.
- Rejet automatique des utilisateurs de moins de 18 ans.

### 💼 Interface utilisateur après connexion
- **Afficher les informations personnelles**
- **Ajouter de l'argent** au compte
- **Effectuer un virement bancaire** (avec vérification du bénéficiaire)
- **Déposer une réclamation**
- **Se déconnecter**

---

## 🗄️ Structure des données

Le projet repose sur une **structure `struct`** définissant un compte bancaire :

```c
struct compte_bancaire {
    char NOM[40];
    char PRENOM[40];
    char CIN[8];
    int AGE;
    char ADRESSE[100];
    char TELE[10];
    float MONTANT;
    char EMAIL[100];
    char PASSWORD[40];
};
```
<img width="601" height="328" alt="image" src="https://github.com/user-attachments/assets/1ef39bd8-ec06-4183-b4f4-e1d0bb0f40f5" />
