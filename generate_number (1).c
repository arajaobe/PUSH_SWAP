/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samrazaf <samrazaf@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:03:08 by samrazaf          #+#    #+#             */
/*   Updated: 2026/03/10 15:03:12 by samrazaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr[501];
    int i, j, temp;

    // Remplir le tableau de 0 à 500
    for(i = 0; i <= 500; i++) {
        arr[i] = i;
    }

    // Initialiser le générateur aléatoire
    srand(time(NULL));

    // Mélanger le tableau (Fisher-Yates)
    for(i = 500; i > 0; i--) {
        j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Afficher les 500 premiers nombres
    for(i = 0; i < 500; i++) {
        if(i < 499)
            printf("%d, ", arr[i]);
        else
            printf("%d", arr[i]);
    }

    return 0;
}
