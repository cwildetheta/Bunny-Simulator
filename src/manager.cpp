#include "manager.h"
#include "bunny.h"
#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip>

std::string colour_list[4] = {"White", "Black", "Brown", "Spotted"}; //Possible colours
std::string gender_list[2] = {"Male", "Female"};
std::string male_name_list[1000] = {"Oliver", "George", "Arthur", "Noah", "Muhammad", "Leo", "Oscar", "Harry", "Archie", "Jack", "Henry", "Charlie", "Freddie", "Theodore", "Thomas", "Finley", "Theo", "Alfie", "Jacob", "William", "Isaac", "Tommy", "Joshua", "James", "Lucas", "Alexander", "Arlo", "Roman", "Edward", "Elijah", "Teddy", "Mohammed", "Max", "Adam", "Albie", "Ethan", "Logan", "Joseph", "Sebastian", "Benjamin", "Harrison", "Mason", "Rory", "Reuben", "Luca", "Louie", "Samuel", "Reggie", "Jaxon", "Daniel", "Hugo", "Louis", "Jude", "Ronnie", "Dylan", "Zachary", "Albert", "Hunter", "Ezra", "David", "Frankie", "Toby", "Frederick", "Carter", "Gabriel", "Grayson", "Riley", "Jesse", "Hudson", "Bobby", "Rowan", "Jenson", "Finn", "Michael", "Mohammad", "Stanley", "Felix", "Jasper", "Liam", "Milo", "Sonny", "Oakley", "Elliot", "Chester", "Caleb", "Harvey", "Elliott", "Charles", "Ellis", "Jackson", "Alfred", "Ollie", "Leon", "Yusuf", "Ralph", "Otis", "Harley", "Ibrahim", "Jayden", "Myles", "Ryan", "Blake", "Kai", "Tobias", "Austin", "Rupert", "Jake", "Alex", "Luke", "Eli", "Nathan", "Dominic", "Elias", "Matthew", "Musa", "Lewis", "Jaxson", "Patrick", "Vinnie", "Aaron", "Aiden", "Billy", "Ruben", "Dexter", "Robert", "Brody", "Vincent", "Leonardo", "Cody", "Eric", "Beau", "Ayaan", "Owen", "Jax", "Levi", "Parker", "Joey", "Muhammed", "Evan", "Tyler", "Ali", "Marley", "Rex", "Miles", "Wilfred", "Robin", "Jonah", "Nathaniel", "Lincoln", "John", "Yahya", "Bodhi", "Jamie", "Lenny", "Kevin", "Cooper", "Maxwell", "Connor", "River", "Zakariya", "Callum", "Joel", "Rocco", "Isaiah", "Phoenix", "Anthony", "Kayden", "Axel", "Finlay", "Spencer", "Syed", "Archer", "Frank", "Idris", "Seth", "Nicholas", "Kian", "Maximilian", "Christopher", "Lorenzo", "Zayn", "Raphael", "Cole", "Abdullah", "Enzo", "Eesa", "Rafael", "Rayan", "Aidan", "Asher", "Remy", "Filip", "Mohamed", "Zion", "Brodie", "Kit", "Matei", "Cameron", "Matteo", "Xander", "Maximus", "Sidney", "Mateo", "Ted", "Ahmed", "Kobe", "Xavier", "Hamza", "Omar", "Abel", "Abdul", "Otto", "Barnaby", "Jason", "Bertie", "Francis", "Flynn", "Eddie", "Mustafa", "Jordan", "Tristan", "Rio", "Eden", "Reginald", "Rhys", "Bailey", "Peter", "Leonard", "Rayyan", "Rudy", "Kaiden", "Nico", "Christian", "Lukas", "Ayan", "Jakub", "Zain", "Cillian", "Coby", "Marcus", "Mark", "Zac", "Adrian", "Antoni", "Casper", "Romeo", "Jonathan", "Jensen", "Josiah", "Victor", "Oskar", "Kylo", "Douglas", "Fraser", "Nicolas", "Zayan", "Rafferty", "Dominik", "Zack", "Sam", "Monty", "Denis", "Ralphie", "Micah", "Stefan", "Amir", "Andrew", "Zayd", "Hector", "Lennon", "Rafe", "Rohan", "Damian", "Umar", "Freddy", "Ivan", "Finnley", "Franklin", "Wyatt", "Bradley", "Julian", "Martin", "Kingsley", "Corey", "Kairo", "Mylo", "Barney", "Colby", "Hassan", "Hayden", "Aryan", "Ahmad", "Alexandru", "Ismail", "Walter", "Ayden", "Amari", "Alan", "Conor", "Ezekiel", "Ernest", "Jan", "Hendrix", "Teddie", "Luka", "Morgan", "Ronan", "Azaan", "Fletcher", "Quinn", "Carson", "Fabian", "Rufus", "Cassius", "Dougie", "Nate", "Marcel", "Huxley", "Malachi", "Aarav", "Casey", "Chase", "Layton", "Kacper", "Osian", "Sami", "Ben", "Emmanuel", "Zayaan", "Harris", "Darius", "Edison", "Milan", "Haris", "Greyson", "Olly", "Maddox", "Danny", "Elis", "Ashton", "Cian", "Aleksander", "Jeremiah", "Kiaan", "Zach", "Erik", "Andrei", "Lachlan", "Percy", "Woody", "Richard", "Tate", "Harri", "Cohen", "Rudi", "Jace", "Reign", "Franciszek", "Ace", "Arham", "Bear", "Ilyas", "Philip", "Aron", "Remi", "Atlas", "Ernie", "Declan", "Kobi", "Koby", "Yunus", "Cruz", "Taylor", "Ayman", "Cairo", "Joe", "Angus", "Ari", "Jimmy", "Santiago", "Antonio", "Jay", "Lennox", "Hugh", "Kaleb", "Lochlan", "Paul", "Issac", "Timothy", "Malik", "Solomon", "Khalil", "Magnus", "Zak", "Junior", "Leighton", "Zachariah", "Dennis", "Shay", "Arjun", "Bilal", "Bruno", "Eduard", "Hussain", "Odin", "Brandon", "Clayton", "Kasper", "Orson", "Ismaeel", "Johnny", "Laurence", "Montgomery", "Nikodem", "Ryder", "Tomos", "Vlad", "Ewan", "Simon", "Aahil", "Jac", "Kieran", "Tomas", "Sullivan", "Diego", "Anas", "Dawud", "Orion", "Sulaiman", "Tymon", "Avery", "Hasan", "Ibraheem", "Niall", "Reece", "Hamish", "Khalid", "Marshall", "Nikolas", "Preston", "Rome", "Zane", "Atticus", "Isa", "Kobie", "Rares", "Travis", "Kyle", "Leonidas", "Maksymilian", "Ziggy", "Szymon", "Edwin", "Hughie", "Tommy-lee", "Aadam", "Abraham", "Buddy", "Luis", "Malakai", "Rayaan", "Vihaan", "Yaqub", "Alistair", "Arnie", "Haider", "Beauden", "Jaden", "Keegan", "Laith", "Mathias", "Vinny", "Koa", "Wilbur", "Archibald", "Dante", "Kenzo", "Rian", "Jago", "Yousef", "Yuvraj", "Brooklyn", "Ianis", "Keyaan", "Lennie", "Loki", "Tudor", "Jaiden", "Mario", "Miguel", "Usman", "Calvin", "Judah", "Lucian", "Mikaeel", "Albi", "Aydin", "Jaxx", "Keanu", "Georgie", "Kane", "Maxim", "Prince", "Yaseen", "Asa", "Fox", "Mikolaj", "Zakaria", "Emilio", "Josh", "Kayson", "Sean", "Ayyub", "Euan", "Faris", "Huzaifa", "Kyrie", "Marco", "Maverick", "Olivier", "Regan", "Robbie", "Teo", "Aaryan", "Bryan", "Cassian", "Matias", "Matthias", "Aayan", "Hashim", "Jonas", "Osman", "Troy", "Yasin", "Hadley", "Hari", "Kareem", "Oliwier", "Ruairi", "Tom", "Noel", "Teodor", "Thiago", "Amos", "Dalton", "Dion", "Idrees", "Jayce", "Sultan", "Zaid", "Caiden", "Dawson", "Justin", "Kabir", "Lawrence", "Lucca", "Raheem", "Tadhg", "Ashley", "Caspian", "Kody", "Nolan", "Raife", "Azlan", "Miller", "Stephen", "Tommie", "Cai", "Clark", "Emir", "Emmett", "Lowen", "Macsen", "Reid", "Sulayman", "Mikael", "Ozzy", "Ralphy", "August", "Deen", "Eisa", "Emanuel", "Forrest", "Fred", "Haroon", "Ivor", "Alby", "Alessandro", "Bentley", "Brian", "Dillon", "Israel", "Kyro", "Md", "Orlando", "Ray", "Shayan", "Ian", "Omari", "Zidan", "Aariz", "Caden", "Deniz", "Esa", "Fionn", "Heath", "Igor", "Kye", "Tyson", "Zaviyar", "Ahad", "Andre", "Aston", "Giovanni", "Imran", "Ioan", "Jovan", "Zayden", "Ayub", "Ishaan", "Kylan", "Steven", "Caelan", "Karter", "Killian", "Zayyan", "Abdulrahman", "Amaan", "Angelo", "Anton", "Clay", "Dawid", "Francesco", "Harlan", "Kyan", "Raymond", "Rueben", "Theodor", "Wesley", "Ammar", "Bowie", "Krish", "Laurie", "Moses", "Natan", "Presley", "Taha", "Vladimir", "Wiktor", "Yanis", "Abu", "Armaan", "Henley", "Michal", "Mikail", "Bruce", "Dean", "Elio", "Emil", "Harlow", "Ishaq", "Ivo", "Kyran", "Samson", "Talha", "Yousuf", "Zakariyya", "Andreas", "Coen", "Dorian", "Franky", "Henri", "Izaan", "Ronald", "Saad", "Saif", "Winston", "Zayne", "Adyan", "Brayden", "Cayden", "Cyrus", "Daniyal", "Hadi", "Jett", "Miran", "Ned", "Neo", "Roscoe", "Amar", "Aubrey", "Benedict", "Caspar", "Iosif", "Mckenzie", "Roan", "Simeon", "Tymoteusz", "Fynn", "Hubert", "Ivar", "Karim", "Raiden", "Seb", "Tiago", "Abbas", "Alec", "Deacon", "Denny", "Emrys", "Fergus", "Ismael", "Karson", "Qasim", "Saint", "Santino", "Silas", "Veer", "King", "Kristian", "Rishi", "Stanislaw", "Colton", "Eddison", "Gray", "Ignacy", "Issa", "Kaden", "Kenny", "Kyron", "Raees", "Rico", "Rocky", "Safwan", "Shahzain", "Wren", "Yasir", "Zidane", "Damien", "Lawson", "Lorcan", "Sahib", "Suleiman", "Yusha", "Antony", "Aris", "Arnold", "Boris", "Deon", "Ekam", "Eyad", "Forest", "Fredrick", "Viaan", "Andy", "Ayaz", "Curtis", "Eoin", "Jeremy", "Mehmet", "Mikey", "Niko", "Omer", "Rehan", "Tony", "Ciaran", "Cobie", "Cosmo", "Edmund", "Izaiah", "Jamal", "Jaylen", "Kade", "Oisin", "Rafi", "Rogan", "Saxon", "Scott", "Valentino", "Vivaan", "Abdurrahman", "Alexandros", "Artie", "Artur", "Avi", "Dhruv", "Faizan", "Hashir", "Jad", "Lee", "Ovie", "Sacha", "Shiloh", "Viktor", "Wade", "Arin", "Arvin", "Bodie", "Chaim", "Gideon", "Kaison", "Mahir", "Musab", "Reagan", "Taron", "Trent", "Uzair", "Warren", "Youssef", "Zaki", "Zander", "Bjorn", "Bleu", "Bogdan", "Danyal", "Digby", "Emerson", "Gruffydd", "Hakeem", "Mahdi", "Arjan", "Benny", "Herbie", "Ivaan", "Jakob", "Lake", "Rohaan", "Soren", "Adriel", "Alfie-james", "Ariyan", "Axl", "Eren", "Hasnain", "Kaiser", "Kayan", "Klay", "Renzo", "Salman", "Sid", "Subhan", "Sufyan", "Wilf", "Yousif", "Devon", "Gene", "Guy", "Hamdan", "Huw", "Indy", "Kiyan", "Mateusz", "Raul", "Reyan", "Sunny", "Aarush", "Alessio", "Aras", "Bobbie", "Braxton", "Cristian", "Denver", "Drew", "Elyas", "Giorgio", "Julius", "Kendrick", "Kole", "Lando", "Layth", "Matas", "Moshe", "Obie", "Raja", "Timur", "Tomi", "Zakariyah", "Addison", "Ameer", "Arian", "Benas", "Bernard", "Boden", "Bowen", "Casian", "Chance", "Diyan", "Edgar", "Elvis", "Franco", "Henryk", "Jayson", "Karam", "Mohamad", "Reyansh", "Ricardo", "Shivansh", "Ajay", "Arman", "Chris", "Damon", "Essa", "Gethin", "Hunter-lee", "Izhaan", "Jai", "Jibreel", "Keaton", "Luqman", "Manraj", "Montague", "Nathanael", "Nuh", "Patrik", "Riyan", "Ryker", "Sahil", "Samir", "Sol", "Zephaniah", "Abubakar", "Abubakr", "Aneurin", "Arlen", "Arlie", "Conrad", "Denzel", "Dilan", "Gregory", "Harper", "Harun", "Herbert", "Huey", "Ishaaq", "Jameson", "Kajus", "Moise", "Paddy", "Riaan", "Roux", "Shane", "Shaun", "Younes", "Abdullahi", "Adnan", "Ayoub", "Ayrton", "Byron", "Carlos", "Farhan", "Fateh", "Griffin", "Hezekiah", "Lloyd", "Loui", "Markas", "Mikhail", "Richie", "Wilson", "Wolf", "Zackary", "Adonis", "Aman", "Aran", "Ares", "Arran", "Aryaan", "Dara", "Devansh", "Elian", "Eryk", "Francisco", "Gus", "Haaris", "Hamzah", "Jadon", "Kingston", "Kohen", "Kuba", "Lockie", "Malcolm", "Manuel", "Marlo", "Pablo", "Rudra", "Rylee", "Salah", "Sonnie", "Taran", "Valentin", "Younis", "Zorawar", "Abdulaziz", "Acer", "Aj", "Akram", "Alexandre", "Alvey", "Aronas", "Bartosz"};
std::string female_name_list[1000] = {"Olivia", "Amelia", "Isla", "Ava", "Mia", "Ivy", "Lily", "Isabella", "Rosie", "Sophia", "Grace", "Freya", "Willow", "Florence", "Emily", "Ella", "Poppy", "Evie", "Elsie", "Charlotte", "Evelyn", "Sienna", "Sofia", "Daisy", "Phoebe", "Sophie", "Alice", "Harper", "Matilda", "Ruby", "Emilia", "Maya", "Millie", "Isabelle", "Eva", "Luna", "Jessica", "Ada", "Aria", "Arabella", "Maisie", "Esme", "Eliza", "Penelope", "Bonnie", "Chloe", "Mila", "Violet", "Hallie", "Scarlett", "Layla", "Imogen", "Eleanor", "Molly", "Harriet", "Elizabeth", "Thea", "Erin", "Lottie", "Emma", "Rose", "Delilah", "Bella", "Aurora", "Lola", "Nancy", "Ellie", "Mabel", "Lucy", "Ayla", "Maria", "Orla", "Zara", "Robyn", "Hannah", "Gracie", "Iris", "Jasmine", "Darcie", "Margot", "Holly", "Amelie", "Amber", "Georgia", "Edith", "Maryam", "Abigail", "Myla", "Anna", "Clara", "Lilly", "Lyra", "Summer", "Maeve", "Heidi", "Elodie", "Lyla", "Eden", "Olive", "Aisha", "Lara", "Sara", "Felicity", "Fatima", "Annabelle", "Esmae", "Amaya", "Zoe", "Beatrice", "Hope", "Nevaeh", "Francesca", "Mollie", "Edie", "Martha", "Sarah", "Autumn", "Victoria", "Marnie", "Nellie", "Pippa", "Darcy", "Ottilie", "Indie", "Aaliyah", "Lexi", "Darcey", "Savannah", "Eloise", "Anaya", "Julia", "Annie", "Zainab", "Arya", "Maddison", "Alexandra", "Isabel", "Lydia", "Niamh", "Elena", "Frankie", "Ariana", "Leah", "Nova", "Nina", "Paisley", "Ayda", "Anastasia", "Connie", "Gabriella", "River", "Sadie", "Cora", "Hazel", "Nora", "Tilly", "Mya", "Primrose", "Isobel", "Amara", "Rosa", "Skylar", "Zoya", "Beatrix", "Faith", "Penny", "Esther", "Skye", "Piper", "Madison", "Callie", "Aoife", "Alba", "Zahra", "Dorothy", "Amira", "Hanna", "Laura", "Betsy", "Cleo", "Ophelia", "Harlow", "Khadija", "Athena", "Naomi", "Ariella", "Lena", "Natalia", "Paige", "Brooke", "Maggie", "Eve", "Maia", "Remi", "Hollie", "Lilah", "Liliana", "Ayat", "Lucia", "India", "Leila", "Eliana", "Aurelia", "Effie", "Polly", "Harley", "Everly", "Lillie", "Alayna", "Safa", "Hana", "Talia", "Alyssa", "Seren", "Maja", "Billie", "Kiara", "Wren", "Skyla", "Georgie", "Liyana", "Hattie", "Winnie", "Inaaya", "Alana", "Bethany", "Dua", "Lacey", "Halle", "Ivy-Rose", "Riley", "Emmie", "Megan", "Nelly", "Etta", "Rebecca", "Melissa", "Aubrey", "Khadijah", "Valentina", "Amelia-Rose", "Astrid", "Haniya", "Isla-Rose", "Lana", "Aliza", "Nyla", "Aiza", "Antonia", "Quinn", "Tabitha", "Alessia", "Belle", "Nola", "Elise", "Clementine", "Lila", "Aleena", "Ida", "Lois", "Mariam", "Alaia", "Ayesha", "Amina", "April", "Vienna", "Alisha", "Ayah", "Josephine", "Miriam", "Pearl", "Amal", "Dottie", "Hafsa", "Tallulah", "Josie", "Laila", "Winter", "Amy", "Ava-Rose", "Nicole", "Annabel", "Anya", "Noor", "Norah", "Georgina", "Neve", "Alaya", "Gabriela", "Melody", "Mary", "Mirha", "Syeda", "Keira", "Stella", "Kayla", "Libby", "Everleigh", "Jessie", "Zofia", "Zuzanna", "Faye", "Peyton", "Alina", "Alma", "Nia", "Inaya", "Saoirse", "Katie", "Ella-Rose", "Fatimah", "Nadia", "Alicia", "Diana", "Rosalie", "Aizah", "Flora", "Reeva", "Audrey", "Daphne", "Dolly", "Hawa", "Jemima", "Madeleine", "Nylah", "Rae", "Aliyah", "Cara", "Helena", "Aya", "Arianna", "Yusra", "Emmeline", "Lillian", "Ayra", "Bella-Rose", "Wynter", "Emelia", "Yasmin", "Ariya", "Hoorain", "Miley", "Madeline", "Blossom", "Halima", "Zaynab", "Daria", "Nell", "Anais", "Honey", "Inayah", "Frances", "Rachel", "Maeva", "Marley", "Verity", "Amirah", "Avery", "Margaret", "Fern", "Iyla", "Lexie", "Lily-Rose", "Theodora", "Elisa", "Mali", "Philippa", "Constance", "Harmony", "Beau", "Jannat", "Addison", "Aubree", "Brianna", "Maisy", "Amayah", "Ava-Mae", "Demi", "Eadie", "Fleur", "Serena", "Gianna", "Leia", "Pixie", "Adeline", "Arla", "Vivienne", "Evangeline", "Alicja", "Aida", "Ffion", "Meadow", "Michelle", "Minnie", "Raya", "Sapphire", "Amalia", "Robin", "Angel", "Imaan", "Lia", "Bianca", "Erica", "Lina", "Hania", "Eira", "Natalie", "Cecilia", "Elle", "Emilie", "Juno", "Oliwia", "Aiyla", "Betty", "Marwa", "Agnes", "Catherine", "Macie", "Ana", "Dolcie", "Gracie-Mae", "Leyla", "Lucie", "Peggy", "Sylvie", "Aayat", "Freyja", "Iqra", "Lily-Mae", "Hiba", "Jennifer", "Liana", "Isra", "Pola", "Rowan", "Kaia", "Klara", "Nala", "Cali", "Iona", "Ocean", "Celine", "Myah", "Octavia", "Aila", "Camilla", "Kira", "Mae", "Aqsa", "Ciara", "Phoenix", "Anayah", "Romy", "Maddie", "Noa", "Ruqayyah", "Mia-Rose", "Selena", "Tia", "Fiadh", "Olivia-Rose", "Siyana", "Ayana", "Blake", "Haleema", "Harper-Rose", "Henrietta", "Juniper", "Rosemary", "Tillie", "Yara", "Amiyah", "Anabia", "Erika", "Lea", "Rhea", "Sydney", "Aminah", "Annabella", "Ela", "Ember", "Gabrielle", "Joanna", "Lilia", "Reya", "Adelaide", "Alys", "Ameera", "Elsie-Mae", "Kyra", "Mira", "Stephanie", "Winifred", "Ellen", "Elora", "Esmee", "Evelina", "Genevieve", "Shelby", "Tiana", "Alayah", "Emmy", "Safiyyah", "Stefania", "Aaminah", "Asiya", "Ebony", "Isla-Mae", "Lilith", "Mara", "Stevie", "Zoey", "Raven", "Coco", "Eshaal", "Hafsah", "Izabella", "Kara", "Karina", "Sana", "Aliya", "Dakota", "Lauren", "Remy", "Aniyah", "Ariah", "Arielle", "Caitlin", "Hayley", "Indigo", "Jorgie", "Joy", "Louisa", "Milena", "Ivy-Mae", "Myra", "Abeeha", "Adaline", "Destiny", "Elsa", "Kaya", "Livia", "Margo", "Zuri", "Aarya", "Fearne", "Katherine", "Lilian", "Renee", "Celeste", "Daisy-Mae", "Mina", "Sasha", "Siena", "Arwa", "Cassie", "Emaan", "Tara", "Aleksandra", "Alexis", "Alyssia", "Brooklyn", "Duaa", "Ellie-Mae", "Giulia", "Indiana", "Lili", "Louise", "Milana", "Sumayyah", "Alara", "Elara", "Meredith", "Mylah", "Neave", "Orlaith", "Taylor", "Margaux", "Rumaysa", "Sabrina", "Safiya", "Adriana", "Dahlia", "Gloria", "Kyla", "Naya", "Ruth", "Theia", "Arwen", "Ava-Grace", "Cassandra", "Kitty", "Minahil", "Persephone", "Shanaya", "Tessa", "Aairah", "Darla", "Ella-Mae", "Leonie", "Lilly-Rose", "Paris", "Scarlet", "Alia", "Hermione", "Riya", "Safaa", "Samantha", "Ameerah", "Claudia", "Elina", "Ines", "Mahnoor", "Manha", "Miya", "Tiffany", "Camille", "Carla", "Hailey", "Laiba", "Layan", "Rebeca", "Zoha", "Aysha", "Gaia", "Jade", "Kiera", "Macy", "Maira", "Skyler", "Amna", "Cataleya", "Evie-Mae", "Liberty", "May", "Nela", "Andreea", "Cassidy", "Jannah", "Malaika", "Saskia", "Wiktoria", "Ariyah", "Bobbie", "Elowen", "Hettie", "Leilani", "Macey", "Michaela", "Morgan", "Nusaybah", "Rumaisa", "Soraya", "Sylvia", "Amari", "Daniela", "Elif", "Elin", "Imani", "Irha", "Kiana", "Melisa", "Natasha", "Roma", "Amani", "Daniella", "Elsie-Rose", "Evie-Rose", "Hadiya", "Isabella-Rose", "Tahlia", "Theadora", "Vanessa", "Aaira", "Ayeza", "Azra", "Bailey", "Darcie-Mae", "Iman", "Liya", "Rita", "Veronica", "Alannah", "Alisa", "Allegra", "Angela", "Elissa", "Frida", "Lainey", "Lilianna", "Lilly-Mae", "Malak", "Marlie", "Rahma", "Reina", "Romilly", "Saffron", "Sia", "Una", "Adelina", "Alanna", "Amelia-Grace", "Carys", "Juliette", "Milly", "Priya", "Yasmine", "Zadie", "Zayna", "Adalyn", "Antonina", "Ariel", "Gia", "Humaira", "Kornelia", "Mahira", "Meghan", "Melina", "Nella", "Alya", "Angelica", "Aura", "Cecily", "Delia", "Diya", "Evalyn", "Husna", "Lacie", "Marina", "Melanie", "Millie-Mae", "Rosanna", "Ruby-Rose", "Thalia", "Alesha", "Amanda", "Ava-May", "Charlie", "Cordelia", "Everley", "Jasmin", "Kaja", "Leona", "Lylah", "Nyra", "Roxy", "Sienna-Rose", "Zelda", "Agatha", "Aimee", "Angelina", "Ashley", "Asiyah", "Chiara", "Eryn", "Ettie", "Helen", "Marcie", "Marla", "Molly-Mae", "Princess", "Roxanne", "Savanna", "Storm", "Crystal", "Daisie", "Eleni", "Ingrid", "Joni", "Roza", "Aylah", "Aylin", "Dulcie", "Ema", "Ferne", "Isobelle", "Juliet", "Kali", "Kate", "Keziah", "Layla-Rose", "Lily-May", "Lorena", "Maliha", "Neriah", "Nieve", "Patricia", "Reign", "Ria", "Ruby-Mae", "Sonia", "Alaina", "Alexia", "Ayaat", "Enya", "Gwen", "Halimah", "Hareem", "Hawwa", "Haya", "Millie-Rose", "Minha", "Naila", "Nour", "Renesmae", "Trinity", "Alissa", "Cerys", "Chaya", "Elspeth", "Harleen", "Indi", "Kathleen", "Nikola", "Olivia-Grace", "Parker", "Rayna", "Renesmee", "Safiyah", "Sky", "Amyra", "Caoimhe", "Casey", "Christina", "Esmai", "Harlie", "Ioana", "Malia", "Marie", "Marlowe", "Nancie", "Poppie", "Raina", "Rania", "Samira", "Selina", "Tala", "Tamara", "Vera", "Aasiyah", "Annalise", "Bea", "Chelsea", "Eleri", "Elisabeth", "Isla-Rae", "Kaira", "Lavinia", "Leela", "Leena", "Raisa", "Renae", "Adele", "Artemis", "Asma", "Carmen", "Cecelia", "Celia", "Dalia", "Danielle", "Dollie", "Huda", "Izabela", "Jocelyn", "Kinza", "Martina", "Maysa", "Ryleigh", "Siya", "Sumaya", "Teodora", "Alivia", "Amarah", "Andrea", "Anika", "Bobbi", "Brielle", "Delilah-Rose", "Dixie", "Enid", "Georgiana", "Greta", "Ilyana", "Lisa", "Medeea", "Millicent", "Nila", "Nyah", "Paloma", "Payton", "Rosabella", "Roseanna", "Willow-Rose", "Beatriz", "Cadi", "Dania", "Darcie-Rae", "Dina", "Elliana", "Ellie-May", "Ivie", "June", "Lorelai", "Lowri", "Mannat", "Marta", "Riva", "Roisin", "Salma", "Shiloh", "Sidra", "Taliah", "Viola", "Xanthe", "Zunairah", "Amaia", "Ayva", "Elaina", "Everlyn", "Harleigh", "Isabela", "Iylah", "Lilliana", "Lola-Rose", "Luna-Rae", "Milan", "Nel", "Asees", "Ezmae", "Hadley", "Harriett", "Isha", "Lyla-Rose", "Miah", "Miruna", "Olympia", "Romi", "Romie", "Summer-Rose", "Zaina", "Bianka", "Deborah", "Elsie-May", "Florrie", "Gracie-May", "Harper-Rae", "Heather", "Hidayah", "Ilinca", "Izzy", "Jana", "Merryn", "Monroe", "Valencia", "Amaira", "Anastazja", "Aurora-Rose", "Dotty", "Efa", "Hajra", "Jenna", "Jiya", "Lillie-Mae", "Luella", "Nailah", "Posie", "Scarlett-Rose", "Sunday", "Aadhya", "Aleeza", "Arissa", "Bethan", "Caitlyn", "Camila", "Carolina", "Emilija", "Indy", "Kenza", "Khloe", "Leja", "Leonora", "Mabli", "Mahi", "Nahla", "Nansi", "Oakley", "Rylee", "Saara", "Sama", "Vivian", "Willa", "Aayah", "Ada-Rose", "Amalie", "Amora", "Anne", "Arisha", "Avneet", "Azalea", "Bridget"};
//Above are the male and female name lists, taken from the list of most popular male and female baby names in the UK in 2020

bool manager::bunny_sorter_internal(std::shared_ptr<bunny> object1, std::shared_ptr<bunny> object2) //Algorithm for sorting bunnies by age
{
    return object1->get_age() > object2->get_age();
}
std::shared_ptr<bunny> manager::bunny_factory(std::string colour) //Factory function that generates all the variables of a new bunny, and then returns a shared pointer to a bunny
{
    std::string gender = gender_list[std::rand()%2];
    std::string name((gender == gender_list[0]) ? (male_name_list[std::rand()%1000]) : (female_name_list[std::rand()%1000]));
    int age = 0; //Bunnies are created at age 0
    bool infected = false;
    if(std::rand()%50 == 0){ //1 in 50 chance of a newly created bunny being infected
        infected = true;
    }
    else{
        infected = false;
    }
    std::unique_ptr<bunny> new_bunny = std::make_unique<bunny>(gender, name, age, colour, infected);
    return new_bunny;
}

manager::manager(int num_of_bunnies)
{
    for(int i = 0; i < num_of_bunnies; i++){ //Creates the entered number of starting bunnies
        std::shared_ptr<bunny> new_bunny = bunny_factory(colour_list[std::rand()%4]);
        bunny_list.push_back(new_bunny);
    }
    turns = 0;
}
bool manager::print_out() //The UI print out, handles all inputs and outputs the bunny list
{
    total = 0, male = 0, female = 0, infected_total = 0; //Resetting the stats ready for recalculation
    turns++;
    bool simulation = true;
    if(bunny_list.size() > 0){
        bunny_list.sort(bunny_sorter_internal); //Makes sure the bunnies are sorted, bit redundant as they shouldn't be able to get unsorted, but good to make sure
        std::cout << "The current bunnies are: " << std::endl;
        std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
        for(int i = 0; i < bunny_list.size(); i++){ //Outputting the bunny list, and counting the stats at the same time
            std::cout << std::setw(15) << (*i1)->get_name() << "  " << std::setw(8) << (*i1)->get_gender() << "  " << std::setw(9) << (*i1)->get_colour() << "  " << std::setw(4) << (*i1)->get_age() << "  ";
            if((*i1)->get_infected() == true){
                std::cout << std::setw(10) << "Infected" << std::endl;
            }
            else{
                std::cout << std::setw(10) << "Healthy" << std::endl;
            }
            total++;
            if((*i1)->get_gender() == "Male"){
                male++;
            }
            else{
                female++;
            }
            if((*i1)->get_infected() == true){
                infected_total++;
            }
            ++i1;
        }
        std::cout << "Total: " << total << "  Males: " << male << "  Females: " << female << "  Infected: " << infected_total << "     Current turn: " << turns << std::endl;
        std::cout << "Press q to quit, k to perform a cull, or any other key to continue: ";
        char input;
        std::cin >> input;
        if((input == 'q') || (input == 'Q')){ //Quitting the simulation
            simulation = false;
        }
        if((input == 'k') || (input == 'K')){ //Culling half the bunnies
            cull();
        }
    }
    else{
        std::cout << "All of the bunnies are dead." << std::endl;
        std::cout << "Simulation over." << std::endl;
        simulation = false;
    }
    return simulation;
}
void manager::end_turn() //Manages the end turn functions
{
    aging(); //Handles aging.
    dying(); //Handles dying.
    calculate_infected_total(); //Updating the infected count
    if(infected_total > 0){ //If there are infected bunnies.
        infect(); //Handles the infection spreading.
    }
    breed(); //Handles the breeding.
    system("pause"); //A pause so the user can read the death and birth messages.
    calculate_total(); //Updating the total count
    if(get_total() > 1000){ //If overpopulated.
        cull(); //Handles the bunnies dieing from overpopulation.
    }
}
void manager::aging() //Handles aging and bunnies dying, updated to be less needlessly convoluted
{
    bunny_list.sort(bunny_sorter_internal); //Makes sure the bunnies are sorted, bit redundant as they shouldn't be able to get unsorted, but good to make sure
    std::list<std::shared_ptr<bunny>>::iterator i1 = bunny_list.begin();
    int to_count_through = bunny_list.size();
    for(int i = 0; i < to_count_through; i++){ //Checking through all the bunnies
        (*i1)->increment_age(1);
        ++i1;
    }
}
void manager::dying() //Handles the bunnies dying, split off from aging
{
    std::cout << std::endl;
    std::list<std::shared_ptr<bunny>>::iterator id = bunny_list.begin();
    int to_count_through = bunny_list.size();
    for(int i = 0; i < to_count_through; i++){
        if(((*id)->get_age() > 10) && ((*id)->get_infected() == false)){ //If the conditions for a normal bunny to die are met, it is removed from the list
            std::cout << "Bunny " << (*id)->get_name() << " has died." << std::endl; //Death output message
            id = bunny_list.erase(id);
        }
        else if(((*id)->get_age() > 50) && ((*id)->get_infected() == true)){ //If the conditions for an infected bunny to die are met, it is removed from the list
            std::cout << "Infected Bunny " << (*id)->get_name() << " has died." << std::endl; //Death output message
            id = bunny_list.erase(id);
        }
        else{
            ++id;
        }
    }
    std::cout << std::endl;
}
void manager::infect() //Handles the spread of the infection
{
    std::list<std::shared_ptr<bunny>>::iterator iv = bunny_list.begin();
    std::vector<std::shared_ptr<bunny>> infection_list; //Creates a mirror vector of bunny pointers
    for(int i = 0; i < bunny_list.size(); i++){
        if((*iv)->get_infected() == false){ //Adds bunnies to the mirror vector if they're not infected, and thus are candidates for infection
            infection_list.push_back(*iv);
        }
        ++iv;
    }
    std::random_shuffle(infection_list.begin(), infection_list.end()); //Shuffles the mirror vector, to randomise who's going to get infected
    int counted = 0;
    std::vector<std::shared_ptr<bunny>>::iterator iv2 = infection_list.begin();
    while((infected_total > 0) && (counted < infection_list.size())){ //Runs through the mirror vector infecting bunnies until either all are infected, or the number infected in the loop reaches the number infected already
        (*iv2)->set_infected(true);
        infected_total--;
        ++iv2;
        counted++;
    }
}
void manager::breed() //Handles breeding
{
    std::list<std::shared_ptr<bunny>>::iterator i2 = bunny_list.begin();
    int to_count_through_2 = bunny_list.size();
    bool is_adult_male = false;
    for(int i = 0; i < to_count_through_2; i++){ //Checks that there is an adult male bunny
        if(((*i2)->get_gender() == "Male") && ((*i2)->get_age() > 1) && ((*i2)->get_infected() == false)){
            is_adult_male = true;
        }
        ++i2;
    }
    std::list<std::shared_ptr<bunny>>::iterator i3 = bunny_list.begin();
    if(is_adult_male == true){ //If there is an adult male
        std::cout << std::endl;
        for(int i = 0; i < to_count_through_2; i++){ //Runs through each bunny to find out if they are a healthy adult female
            if(((*i3)->get_gender() == "Female") && ((*i3)->get_age() > 1) && ((*i3)->get_infected() == false)){
                bunny_list.push_back(bunny_factory((*i3)->get_colour())); //For each such bunny, create a new bunny
                std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.end();
                advance(i4, -1);
                if((*i4)->get_infected() == false){
                    std::cout << "Bunny ";
                }
                else{
                    std::cout << "Infected Bunny ";
                }
                std::cout << (*i4)->get_name() << " was born." << std::endl; //Output birth message
            }
            ++i3;
        }
    }
}
void manager::cull() //Handles culling, new and improved version, properly random this time
{
    std::list<std::shared_ptr<bunny>>::iterator i4 = bunny_list.begin();
    std::vector<bool> cull_list; //Creating a mirrow vector of booleans
    for(int i = 0; i < bunny_list.size(); i++){ //The end vector will be the same size as the bunny list
        if(i < bunny_list.size()/2){ //The first half of the array is set to true, the second half to false
            cull_list.push_back(true);
        }
        else{
            cull_list.push_back(false);
        }
    }
    std::random_shuffle(cull_list.begin(), cull_list.end()); //Shuffling the boolean vector. Randomness is in the hands of std now
    std::vector<bool>::iterator ic = cull_list.begin();
    calculate_total(); //Because I'm about to call that value
    std::cout << "Culling " << (bunny_list.size()/2) << " bunnies, " << (get_total()-(bunny_list.size()/2)) << " survive." << std::endl; //Culling output
    system("pause");
    int to_count_through_2 = bunny_list.size();
    for(int i = 0; i < to_count_through_2; i++){ //Working through the boolean array and bunny list side by side
        if((*ic) == true){ //If the value is true, the corresponding bunny in the bunny list is deleted
            i4 = bunny_list.erase(i4);
        }
        else{
            ++i4;
        }
        ++ic;
    }
}

void manager::calculate_infected_total()
{
    std::list<std::shared_ptr<bunny>>::iterator iinfected = bunny_list.begin();
    infected_total = 0;
    for(int i = 0; i < bunny_list.size(); i++){
        if((*iinfected)->get_infected() == true){
            infected_total++;
        }
        ++iinfected;
    }
}
void manager::calculate_male()
{
    std::list<std::shared_ptr<bunny>>::iterator imale = bunny_list.begin();
    male = 0;
    for(int i = 0; i < bunny_list.size(); i++){
        if((*imale)->get_gender() == "Male"){
            male++;
        }
        ++imale;
    }
}
void manager::calculate_female()
{
    std::list<std::shared_ptr<bunny>>::iterator ifemale = bunny_list.begin();
    female = 0;
    for(int i = 0; i < bunny_list.size(); i++){
        if((*ifemale)->get_gender() == "Female"){
            female++;
        }
        ++ifemale;
    }
}
void manager::calculate_total()
{
    total = bunny_list.size();
}

//VARIABLE INTERACTIONS//

int manager::get_infected_total() const
{
    return infected_total;
}
int manager::get_male() const
{
    return male;
}
int manager::get_female() const
{
    return female;
}
int manager::get_total() const
{
    return total;
}