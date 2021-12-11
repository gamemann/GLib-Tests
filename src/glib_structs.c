#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/types.h>

#include <glib.h>

#include "glib_structs.h"

/**
 * @note Useful GHash header file to read => https://github.com/GNOME/glib/blob/main/glib/ghash.h.
**/

int main(int argc, char **argv)
{
    // Create the GHash table using integer hash.
    GHashTable *tbl = g_hash_table_new_full(g_int_hash, g_int_equal, NULL, g_free);

    // We'll want to check the results.
    if (tbl == NULL)
    {
        printf("GHash table failed to initialize.");

        return 1;
    }

    // Iterator.
    unsigned int i;

    // If we have an argument, use that as max entries, otherwise set to default max entries.
    unsigned int max_entries = (argc > 1) ? atoi(argv[1]) : MAX_ENTRIES_DEFAULT;

    // Insert five entries into the table starting from index 0.
    for (i = 0; i < max_entries; i++)
    {
        // Allocate the key and set its values (depending on the value of i).
        struct key *key = g_new0(struct key, 1);
        key->field32_1 = i * 300;
        key->field16_1 = i * 3;
        key->field32_2 = i * 600;
        key->field16_2 = i * 90;

        // Allocate the value and set its values (depending on the value of i).
        struct val *val = g_new0(struct val, 1);
        val->field32_1 = i * 1;
        val->field32_2 = i * 2;
        val->field32_3 = i * 3;
        val->field32_4 = i * 4;
        val->field64_1 = i * 100000;
        val->field64_2 = i * 10000000;

        // Attempt to insert into the table. Will return 1 (true) on success.
        if (g_hash_table_insert(tbl, key, val))
        {
            printf("Successfully inserted entry! Key => %u:%d:%u:%d (%u). Val => %u:%u:%u:%u:%llu:%llu.\n", key->field32_1, key->field16_1, key->field32_2, key->field16_2, i, val->field32_1, val->field32_2, val->field32_3, val->field32_4, val->field64_1, val->field64_2);
        }
    }

    // Print size of table.
    printf("Size of table is now %d (entries).\n", g_hash_table_size(tbl));

    // Loop again and now perform lookups.
    for (i = 0; i < max_entries; i++)
    {
        // Allocate and set key. 
        struct key *key = g_new0(struct key, 1);
        key->field32_1 = i * 300;
        key->field16_1 = i * 3;
        key->field32_2 = i * 600;
        key->field16_2 = i * 90;

        // Perform lookup on hash table. We store the new value as a gpointer (void *).
        gpointer newval = g_hash_table_lookup(tbl, key);

        // Check if the pointer is NULL.
        if (newval != NULL)
        {
            // Now we'll want to cast as our structure.
            struct val *val = (struct val *)newval;

            // Print information.
            printf("Lookup successful! Key => %u:%d:%u:%d (%u). Val => %u:%u:%u:%u:%llu:%llu.\n", key->field32_1, key->field16_1, key->field32_2, key->field16_2, i, val->field32_1, val->field32_2, val->field32_3, val->field32_4, val->field64_1, val->field64_2);
        }
        else
        {
            // Print fail information.
            printf("Failed lookup for index %u. Key => %u:%d:%u:%d.\n", i, key->field32_1, key->field16_1, key->field32_2, key->field16_2);
        }
    }

    // Destroy the table.
    g_hash_table_destroy(tbl);

    // Return success!
    return EXIT_SUCCESS;
}