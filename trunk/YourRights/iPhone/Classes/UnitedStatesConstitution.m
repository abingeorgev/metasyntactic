// Copyright 2010 Cyrus Najmabadi
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, write to the Free Software Foundation, Inc., 51
// Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#import "UnitedStatesConstitution.h"

#import "Amendment.h"
#import "Article.h"
#import "Constitution.h"
#import "Person.h"
#import "Section.h"

@implementation UnitedStatesConstitution

static Constitution* unitedStatesConstitution;

+ (void) setupUnitedStatesConstitution {
    NSString* country = [[NSLocale currentLocale] displayNameForKey:NSLocaleCountryCode value:@"US"];
    Article* article1 =
    [Article articleWithTitle:NSLocalizedString(@"The Legislative Branch", nil)
                         link:@"http://en.wikipedia.org/wiki/Article_One_of_the_United_States_Constitution"
                     sections:[NSArray arrayWithObjects:
     [Section sectionWithText:NSLocalizedString(@"All legislative powers herein granted shall be vested in a Congress of the United States, which shall consist of a Senate and House of Representatives.", nil)],
     [Section sectionWithText:NSLocalizedString(@"The House of Representatives shall be composed of members chosen every second year by the people of the several states, and the electors in each state shall have the qualifications requisite for electors of the most numerous branch of the state legislature.\n\n"
                                                                          @"No person shall be a Representative who shall not have attained to the age of twenty five years, and been seven years a citizen of the United States, and who shall not, when elected, be an inhabitant of that state in which he shall be chosen.\n\n"
                                                                          @"Representatives and direct taxes shall be apportioned among the several states which may be included within this union, according to their respective numbers, which shall be determined by adding to the whole number of free persons, including those bound to service for a term of years, and excluding Indians not taxed, three fifths of all other Persons. The actual Enumeration shall be made within three years after the first meeting of the Congress of the United States, and within every subsequent term of ten years, in such manner as they shall by law direct. The number of Representatives shall not exceed one for every thirty thousand, but each state shall have at least one Representative; and until such enumeration shall be made, the state of New Hampshire shall be entitled to chuse three, Massachusetts eight, Rhode Island and Providence Plantations one, Connecticut five, New York six, New Jersey four, Pennsylvania eight, Delaware one, Maryland six, Virginia ten, North Carolina five, South Carolina five, and Georgia three.\n\n"
                                                                          @"When vacancies happen in the Representation from any state, the executive authority thereof shall issue writs of election to fill such vacancies.\n\n"
                                                                          @"The House of Representatives shall choose their speaker and other officers; and shall have the sole power of impeachment.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"The Senate of the United States shall be composed of two Senators from each state, chosen by the legislature thereof, for six years; and each Senator shall have one vote.\n\n"
                                                                          @"Immediately after they shall be assembled in consequence of the first election, they shall be divided as equally as may be into three classes. The seats of the Senators of the first class shall be vacated at the expiration of the second year, of the second class at the expiration of the fourth year, and the third class at the expiration of the sixth year, so that one third may be chosen every second year; and if vacancies happen by resignation, or otherwise, during the recess of the legislature of any state, the executive thereof may make temporary appointments until the next meeting of the legislature, which shall then fill such vacancies.\n\n"
                                                                          @"No person shall be a Senator who shall not have attained to the age of thirty years, and been nine years a citizen of the United States and who shall not, when elected, be an inhabitant of that state for which he shall be chosen.\n\n"
                                                                          @"The Vice President of the United States shall be President of the Senate, but shall have no vote, unless they be equally divided.\n\n"
                                                                          @"The Senate shall choose their other officers, and also a President pro tempore, in the absence of the Vice President, or when he shall exercise the office of President of the United States.\n\n"
                                                                          @"The Senate shall have the sole power to try all impeachments. When sitting for that purpose, they shall be on oath or affirmation. When the President of the United States is tried, the Chief Justice shall preside: And no person shall be convicted without the concurrence of two thirds of the members present.\n\n"
                                                                                                    @"Judgment in cases of impeachment shall not extend further than to removal from office, and disqualification to hold and enjoy any office of honor, trust or profit under the United States: but the party convicted shall nevertheless be liable and subject to indictment, trial, judgment and punishment, according to law.", nil)],
                                                                                                                                                                                                                                                                        [Section sectionWithText:NSLocalizedString(@"The times, places and manner of holding elections for Senators and Representatives, shall be prescribed in each state by the legislature thereof; but the Congress may at any time by law make or alter such regulations, except as to the places of choosing Senators.\n\n"
                                                                          @"The Congress shall assemble at least once in every year, and such meeting shall be on the first Monday in December, unless they shall by law appoint a different day.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"Each House shall be the judge of the elections, returns and qualifications of its own members, and a majority of each shall constitute a quorum to do business; but a smaller number may adjourn from day to day, and may be authorized to compel the attendance of absent members, in such manner, and under such penalties as each House may provide.\n\n"
                                                                          @"Each House may determine the rules of its proceedings, punish its members for disorderly behavior, and, with the concurrence of two thirds, expel a member.\n\n"
                                                                          @"Each House shall keep a journal of its proceedings, and from time to time publish the same, excepting such parts as may in their judgment require secrecy; and the yeas and nays of the members of either House on any question shall, at the desire of one fifth of those present, be entered on the journal.\n\n"
                                                                          @"Neither House, during the session of Congress, shall, without the consent of the other, adjourn for more than three days, nor to any other place than that in which the two Houses shall be sitting.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"The Senators and Representatives shall receive a compensation for their services, to be ascertained by law, and paid out of the treasury of the United States. They shall in all cases, except treason, felony and breach of the peace, be privileged from arrest during their attendance at the session of their respective Houses, and in going to and returning from the same; and for any speech or debate in either House, they shall not be questioned in any other place.\n\n"
                                                                          @"No Senator or Representative shall, during the time for which he was elected, be appointed to any civil office under the authority of the United States, which shall have been created, or the emoluments whereof shall have been increased during such time: and no person holding any office under the United States, shall be a member of either House during his continuance in office.", nil)],
                                                                                                                                                                                                                                                                                                                [Section sectionWithText:NSLocalizedString(@"All bills for raising revenue shall originate in the House of Representatives; but the Senate may propose or concur with amendments as on other Bills.\n\n"
                                                                          @"Every bill which shall have passed the House of Representatives and the Senate, shall, before it become a law, be presented to the President of the United States; if he approve he shall sign it, but if not he shall return it, with his objections to that House in which it shall have originated, who shall enter the objections at large on their journal, and proceed to reconsider it. If after such reconsideration two thirds of that House shall agree to pass the bill, it shall be sent, together with the objections, to the other House, by which it shall likewise be reconsidered, and if approved by two thirds of that House, it shall become a law. But in all such cases the votes of both Houses shall be determined by yeas and nays, and the names of the persons voting for and against the bill shall be entered on the journal of each House respectively. If any bill shall not be returned by the President within ten days (Sundays excepted) after it shall have been presented to him, the same shall be a law, in like manner as if he had signed it, unless the Congress by their adjournment prevent its return, in which case it shall not be a law.\n\n"
                                                                          @"Every order, resolution, or vote to which the concurrence of the Senate and House of Representatives may be necessary (except on a question of adjournment) shall be presented to the President of the United States; and before the same shall take effect, shall be approved by him, or being disapproved by him, shall be repassed by two thirds of the Senate and House of Representatives, according to the rules and limitations prescribed in the case of a bill.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"The Congress shall have power to lay and collect taxes, duties, imposts and excises, to pay the debts and provide for the common defense and general welfare of the United States; but all duties, imposts and excises shall be uniform throughout the United States;\n\n"
                                                                          @"To borrow money on the credit of the United States;\n\n"
                                                                          @"To regulate commerce with foreign nations, and among the several states, and with the Indian tribes;\n\n"
                                                                          @"To establish a uniform rule of naturalization, and uniform laws on the subject of bankruptcies throughout the United States;\n\n"
                                                                          @"To coin money, regulate the value thereof, and of foreign coin, and fix the standard of weights and measures;\n\n"
                                                                          @"To provide for the punishment of counterfeiting the securities and current coin of the United States;\n\n"
                                                                          @"To establish post offices and post roads;\n\n"
                                                                          @"To promote the progress of science and useful arts, by securing for limited times to authors and inventors the exclusive right to their respective writings and discoveries;\n\n"
                                                                          @"To constitute tribunals inferior to the Supreme Court;\n\n"
                                                                          @"To define and punish piracies and felonies committed on the high seas, and offenses against the law of nations;\n\n"
                                                                          @"To declare war, grant letters of marque and reprisal, and make rules concerning captures on land and water;\n\n"
                                                                          @"To raise and support armies, but no appropriation of money to that use shall be for a longer term than two years;\n\n"
                                                                          @"To provide and maintain a navy;\n\n"
                                                                          @"To make rules for the government and regulation of the land and naval forces;\n\n"
                                                                          @"To provide for calling forth the militia to execute the laws of the union, suppress insurrections and repel invasions;\n\n"
                                                                          @"To provide for organizing, arming, and disciplining, the militia, and for governing such part of them as may be employed in the service of the United States, reserving to the states respectively, the appointment of the officers, and the authority of training the militia according to the discipline prescribed by Congress;\n\n"
                                                                          @"To exercise exclusive legislation in all cases whatsoever, over such District (not exceeding ten miles square) as may, by cession of particular states, and the acceptance of Congress, become the seat of the government of the United States, and to exercise like authority over all places purchased by the consent of the legislature of the state in which the same shall be, for the erection of forts, magazines, arsenals, dockyards, and other needful buildings;--And\n\n"
                                                                          @"To make all laws which shall be necessary and proper for carrying into execution the foregoing powers, and all other powers vested by this Constitution in the government of the United States, or in any department or officer thereof.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"The migration or importation of such persons as any of the states now existing shall think proper to admit, shall not be prohibited by the Congress prior to the year one thousand eight hundred and eight, but a tax or duty may be imposed on such importation, not exceeding ten dollars for each person.\n\n"
                                                                          @"The privilege of the writ of habeas corpus shall not be suspended, unless when in cases of rebellion or invasion the public safety may require it.\n\n"
                                                                          @"No bill of attainder or ex post facto Law shall be passed.\n\n"
                                                                          @"No capitation, or other direct, tax shall be laid, unless in proportion to the census or enumeration herein before directed to be taken.\n\n"
                                                                          @"No tax or duty shall be laid on articles exported from any state.\n\n"
                                                                          @"No preference shall be given by any regulation of commerce or revenue to the ports of one state over those of another: nor shall vessels bound to, or from, one state, be obliged to enter, clear or pay duties in another.\n\n"
                                                                          @"No money shall be drawn from the treasury, but in consequence of appropriations made by law; and a regular statement and account of receipts and expenditures of all public money shall be published from time to time.\n\n"
                                                                          @"No title of nobility shall be granted by the United States: and no person holding any office of profit or trust under them, shall, without the consent of the Congress, accept of any present, emolument, office, or title, of any kind whatever, from any king, prince, or foreign state.", nil)],
                                                                                                              [Section sectionWithText:NSLocalizedString(@"No state shall enter into any treaty, alliance, or confederation; grant letters of marque and reprisal; coin money; emit bills of credit; make anything but gold and silver coin a tender in payment of debts; pass any bill of attainder, ex post facto law, or law impairing the obligation of contracts, or grant any title of nobility.\n\n"
                                                                          @"No state shall, without the consent of the Congress, lay any imposts or duties on imports or exports, except what may be absolutely necessary for executing it's inspection laws: and the net produce of all duties and imposts, laid by any state on imports or exports, shall be for the use of the treasury of the United States; and all such laws shall be subject to the revision and control of the Congress.\n\n"
                                                                          @"No state shall, without the consent of Congress, lay any duty of tonnage, keep troops, or ships of war in time of peace, enter into any agreement or compact with another state, or with a foreign power, or engage in war, unless actually invaded, or in such imminent danger as will not admit of delay.", nil)], nil]];

    Article* article2 =
    [Article articleWithTitle:NSLocalizedString(@"The Presidency", nil)
                         link:@"http://en.wikipedia.org/wiki/Article_Two_of_the_United_States_Constitution"
                     sections:[NSArray arrayWithObjects:
     [Section sectionWithText:NSLocalizedString(@"The executive power shall be vested in a President of the United States of America. He shall hold his office during the term of four years, and, together with the Vice President, chosen for the same term, be elected, as follows:\n\n"
@"Each state shall appoint, in such manner as the Legislature thereof may direct, a number of electors, equal to the whole number of Senators and Representatives to which the State may be entitled in the Congress: but no Senator or Representative, or person holding an office of trust or profit under the United States, shall be appointed an elector.\n\n"
                                                                          @"The electors shall meet in their respective states, and vote by ballot for two persons, of whom one at least shall not be an inhabitant of the same state with themselves. And they shall make a list of all the persons voted for, and of the number of votes for each; which list they shall sign and certify, and transmit sealed to the seat of the government of the United States, directed to the President of the Senate. The President of the Senate shall, in the presence of the Senate and House of Representatives, open all the certificates, and the votes shall then be counted. The person having the greatest number of votes shall be the President, if such number be a majority of the whole number of electors appointed; and if there be more than one who have such majority, and have an equal number of votes, then the House of Representatives shall immediately choose by ballot one of them for President; and if no person have a majority, then from the five highest on the list the said House shall in like manner choose the President. But in choosing the President, the votes shall be taken by States, the representation from each state having one vote; A quorum for this purpose shall consist of a member or members from two thirds of the states, and a majority of all the states shall be necessary to a choice. In every case, after the choice of the President, the person having the greatest number of votes of the electors shall be the Vice President. But if there should remain two or more who have equal votes, the Senate shall choose from them by ballot the Vice President.\n\n"
                                                                          @"The Congress may determine the time of choosing the electors, and the day on which they shall give their votes; which day shall be the same throughout the United States.\n\n"
                                                                          @"No person except a natural born citizen, or a citizen of the United States, at the time of the adoption of this Constitution, shall be eligible to the office of President; neither shall any person be eligible to that office who shall not have attained to the age of thirty five years, and been fourteen Years a resident within the United States.\n\n"
                                                                          @"In case of the removal of the President from office, or of his death, resignation, or inability to discharge the powers and duties of the said office, the same shall devolve on the Vice President, and the Congress may by law provide for the case of removal, death, resignation or inability, both of the President and Vice President, declaring what officer shall then act as President, and such officer shall act accordingly, until the disability be removed, or a President shall be elected.\n\n"
                                                                          @"The President shall, at stated times, receive for his services, a compensation, which shall neither be increased nor diminished during the period for which he shall have been elected, and he shall not receive within that period any other emolument from the United States, or any of them.\n\n"
                                                                          @"Before he enter on the execution of his office, he shall take the following oath or affirmation:--'I do solemnly swear (or affirm) that I will faithfully execute the office of President of the United States, and will to the best of my ability, preserve, protect and defend the Constitution of the United States.'", nil)],
                                                                                                                                                   [Section sectionWithText:NSLocalizedString(@"The President shall be commander in chief of the Army and Navy of the United States, and of the militia of the several states, when called into the actual service of the United States; he may require the opinion, in writing, of the principal officer in each of the executive departments, upon any subject relating to the duties of their respective offices, and he shall have power to grant reprieves and pardons for offenses against the United States, except in cases of impeachment.\n\n"
                                                                          @"He shall have power, by and with the advice and consent of the Senate, to make treaties, provided two thirds of the Senators present concur; and he shall nominate, and by and with the advice and consent of the Senate, shall appoint ambassadors, other public ministers and consuls, judges of the Supreme Court, and all other officers of the United States, whose appointments are not herein otherwise provided for, and which shall be established by law: but the Congress may by law vest the appointment of such inferior officers, as they think proper, in the President alone, in the courts of law, or in the heads of departments.\n\n"
                                                                          @"The President shall have power to fill up all vacancies that may happen during the recess of the Senate, by granting commissions which shall expire at the end of their next session.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"He shall from time to time give to the Congress information of the state of the union, and recommend to their consideration such measures as he shall judge necessary and expedient; he may, on extraordinary occasions, convene both Houses, or either of them, and in case of disagreement between them, with respect to the time of adjournment, he may adjourn them to such time as he shall think proper; he shall receive ambassadors and other public ministers; he shall take care that the laws be faithfully executed, and shall commission all the officers of the United States.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"The President, Vice President and all civil officers of the United States, shall be removed from office on impeachment for, and conviction of, treason, bribery, or other high crimes and misdemeanors.", nil)], nil]];

    Article* article3 =
    [Article articleWithTitle:NSLocalizedString(@"The Judiciary", nil)
                         link:@"http://en.wikipedia.org/wiki/Article_Three_of_the_United_States_Constitution"
                     sections:[NSArray arrayWithObjects:
     [Section sectionWithText:NSLocalizedString(@"The judicial power of the United States, shall be vested in one Supreme Court, and in such inferior courts as the Congress may from time to time ordain and establish. The judges, both of the supreme and inferior courts, shall hold their offices during good behaviour, and shall, at stated times, receive for their services, a compensation, which shall not be diminished during their continuance in office.", nil)],
     [Section sectionWithText:NSLocalizedString(@"The judicial power shall extend to all cases, in law and equity, arising under this Constitution, the laws of the United States, and treaties made, or which shall be made, under their authority;--to all cases affecting ambassadors, other public ministers and consuls;--to all cases of admiralty and maritime jurisdiction;--to controversies to which the United States shall be a party;--to controversies between two or more states;--between a state and citizens of another state;--between citizens of different states;--between citizens of the same state claiming lands under grants of different states, and between a state, or the citizens thereof, and foreign states, citizens or subjects.\n\n"
                                                                          @"In all cases affecting ambassadors, other public ministers and consuls, and those in which a state shall be party, the Supreme Court shall have original jurisdiction. In all the other cases before mentioned, the Supreme Court shall have appellate jurisdiction, both as to law and fact, with such exceptions, and under such regulations as the Congress shall make.\n\n"
                                                                          @"The trial of all crimes, except in cases of impeachment, shall be by jury; and such trial shall be held in the state where the said crimes shall have been committed; but when not committed within any state, the trial shall be at such place or places as the Congress may by law have directed.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"Treason against the United States, shall consist only in levying war against them, or in adhering to their enemies, giving them aid and comfort. No person shall be convicted of treason unless on the testimony of two witnesses to the same overt act, or on confession in open court.\n\n"
                                                                          @"The Congress shall have power to declare the punishment of treason, but no attainder of treason shall work corruption of blood, or forfeiture except during the life of the person attainted.", nil)],
                               nil]];

    Article* article4 =
    [Article articleWithTitle:NSLocalizedString(@"The States", nil)
                         link:@"http://en.wikipedia.org/wiki/Article_Four_of_the_United_States_Constitution"
                     sections:[NSArray arrayWithObjects:
     [Section sectionWithText:NSLocalizedString(@"Full faith and credit shall be given in each state to the public acts, records, and judicial proceedings of every other state. And the Congress may by general laws prescribe the manner in which such acts, records, and proceedings shall be proved, and the effect thereof.", nil)],
     [Section sectionWithText:NSLocalizedString(@"The citizens of each state shall be entitled to all privileges and immunities of citizens in the several states.\n\n"
                                                                          @"A person charged in any state with treason, felony, or other crime, who shall flee from justice, and be found in another state, shall on demand of the executive authority of the state from which he fled, be delivered up, to be removed to the state having jurisdiction of the crime.\n\n"
                                                                          @"No person held to service or labor in one state, under the laws thereof, escaping into another, shall, in consequence of any law or regulation therein, be discharged from such service or labor, but shall be delivered up on claim of the party to whom such service or labor may be due.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"New states may be admitted by the Congress into this union; but no new states shall be formed or erected within the jurisdiction of any other state; nor any state be formed by the junction of two or more states, or parts of states, without the consent of the legislatures of the states concerned as well as of the Congress.\n\n"
                                                                          @"The Congress shall have power to dispose of and make all needful rules and regulations respecting the territory or other property belonging to the United States; and nothing in this Constitution shall be so construed as to prejudice any claims of the United States, or of any particular state.", nil)],
                               [Section sectionWithText:NSLocalizedString(@"The United States shall guarantee to every state in this union a republican form of government, and shall protect each of them against invasion; and on application of the legislature, or of the executive (when the legislature cannot be convened) against domestic violence.", nil)],
                               nil]];

    Article* article5 =
    [Article articleWithTitle:NSLocalizedString(@"The Amendment Process", nil)
                         link:@"http://en.wikipedia.org/wiki/Article_Five_of_the_United_States_Constitution"
                      section:[Section sectionWithText:NSLocalizedString(@"The Congress, whenever two thirds of both houses shall deem it necessary, shall propose amendments to this Constitution, or, on the application of the legislatures of two thirds of the several states, shall call a convention for proposing amendments, which, in either case, shall be valid to all intents and purposes, as part of this Constitution, when ratified by the legislatures of three fourths of the several states, or by conventions in three fourths thereof, as the one or the other mode of ratification may be proposed by the Congress; provided that no amendment which may be made prior to the year one thousand eight hundred and eight shall in any manner affect the first and fourth clauses in the ninth section of the first article; and that no state, without its consent, shall be deprived of its equal suffrage in the Senate.", nil)]];

    Article* article6 =
    [Article articleWithTitle:NSLocalizedString(@"Legal Status of the Constitution", nil)
                         link:@"http://en.wikipedia.org/wiki/Article_Six_of_the_United_States_Constitution"
                      section:[Section sectionWithText:NSLocalizedString(@"All debts contracted and engagements entered into, before the adoption of this Constitution, shall be as valid against the United States under this Constitution, as under the Confederation.\n\n"
                                                                         @"This Constitution, and the laws of the United States which shall be made in pursuance thereof; and all treaties made, or which shall be made, under the authority of the United States, shall be the supreme law of the land; and the judges in every state shall be bound thereby, anything in the Constitution or laws of any State to the contrary notwithstanding.\n\n"
                                                                         @"The Senators and Representatives before mentioned, and the members of the several state legislatures, and all executive and judicial officers, both of the United States and of the several states, shall be bound by oath or affirmation, to support this Constitution; but no religious test shall ever be required as a qualification to any office or public trust under the United States.", nil)]];

    Article* article7 =
    [Article articleWithTitle:NSLocalizedString(@"Ratification", nil)
                         link:@"http://en.wikipedia.org/wiki/Article_Seven_of_the_United_States_Constitution"
                      section:[Section sectionWithText:NSLocalizedString(@"The ratification of the conventions of nine states, shall be sufficient for the establishment of this Constitution between the states so ratifying the same.", nil)]];

    Amendment* amendment1 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Religion, Speech, Press", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/First_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"Congress shall make no law respecting an establishment of religion, or prohibiting the free exercise thereof; or abridging the freedom of speech, or of the press; or the right of the people peaceably to assemble, and to petition the government for a redress of grievances.", nil)];
    Amendment* amendment2 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Right to Bear Arms", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Second_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"A well regulated militia, being necessary to the security of a free state, the right of the people to keep and bear arms, shall not be infringed.", nil)];
    Amendment* amendment3 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Quartering of Troops", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Third_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"No soldier shall, in time of peace be quartered in any house, without the consent of the owner, nor in time of war, but in a manner to be prescribed by law.", nil)];
    Amendment* amendment4 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Search and Seizure", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Fourth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The right of the people to be secure in their persons, houses, papers, and effects, against unreasonable searches and seizures, shall not be violated, and no warrants shall issue, but upon probable cause, supported by oath or affirmation, and particularly describing the place to be searched, and the persons or things to be seized.", nil)];
    Amendment* amendment5 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Due Process", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Fifth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"No person shall be held to answer for a capital, or otherwise infamous crime, unless on a presentment or indictment of a grand jury, except in cases arising in the land or naval forces, or in the militia, when in actual service in time of war or public danger; nor shall any person be subject for the same offense to be twice put in jeopardy of life or limb; nor shall be compelled in any criminal case to be a witness against himself, nor be deprived of life, liberty, or property, without due process of law; nor shall private property be taken for public use, without just compensation.", nil)];
    Amendment* amendment6 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Right to Counsel", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Sixth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"In all criminal prosecutions, the accused shall enjoy the right to a speedy and public trial, by an impartial jury of the state and district wherein the crime shall have been committed, which district shall have been previously ascertained by law, and to be informed of the nature and cause of the accusation; to be confronted with the witnesses against him; to have compulsory process for obtaining witnesses in his favor, and to have the assistance of counsel for his defense.", nil)];
    Amendment* amendment7 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Jury Trial", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Seventh_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"In suits at common law, where the value in controversy shall exceed twenty dollars, the right of trial by jury shall be preserved, and no fact tried by a jury, shall be otherwise reexamined in any court of the United States, than according to the rules of the common law.", nil)];
    Amendment* amendment8 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Cruel and Unusual Punishment", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Eighth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"Excessive bail shall not be required, nor excessive fines imposed, nor cruel and unusual punishments inflicted.", nil)];
    Amendment* amendment9 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Non-Enumerated Rights", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Ninth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The enumeration in the Constitution, of certain rights, shall not be construed to deny or disparage others retained by the people.", nil)];
    Amendment* amendment10 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"States Rights", nil)
                                year:1791
                                link:@"http://en.wikipedia.org/wiki/Tenth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The powers not delegated to the United States by the Constitution, nor prohibited by it to the states, are reserved to the states respectively, or to the people.", nil)];
    Amendment* amendment11 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Suits Against a State", nil)
                                year:1795
                                link:@"http://en.wikipedia.org/wiki/Eleventh_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The judicial power of the United States shall not be construed to extend to any suit in law or equity, commenced or prosecuted against one of the United States by citizens of another state, or by citizens or subjects of any foreign state.", nil)];
    Amendment* amendment12 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"President and VP Election", nil)
                                year:1804
                                link:@"http://en.wikipedia.org/wiki/Twelfth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The electors shall meet in their respective states and vote by ballot for President and Vice-President, one of whom, at least, shall not be an inhabitant of the same state with themselves; they shall name in their ballots the person voted for as President, and in distinct ballots the person voted for as Vice-President, and they shall make distinct lists of all persons voted for as President, and of all persons voted for as Vice-President, and of the number of votes for each, which lists they shall sign and certify, and transmit sealed to the seat of the government of the United States, directed to the President of the Senate;--The President of the Senate shall, in the presence of the Senate and House of Representatives, open all the certificates and the votes shall then be counted;--the person having the greatest number of votes for President, shall be the President, if such number be a majority of the whole number of electors appointed; and if no person have such majority, then from the persons having the highest numbers not exceeding three on the list of those voted for as President, the House of Representatives shall choose immediately, by ballot, the President. But in choosing the President, the votes shall be taken by states, the representation from each state having one vote; a quorum for this purpose shall consist of a member or members from two-thirds of the states, and a majority of all the states shall be necessary to a choice. And if the House of Representatives shall not choose a President whenever the right of choice shall devolve upon them, before the fourth day of March next following, then the Vice-President shall act as President, as in the case of the death or other constitutional disability of the President. The person having the greatest number of votes as Vice-President, shall be the Vice-President, if such number be a majority of the whole number of electors appointed, and if no person have a majority, then from the two highest numbers on the list, the Senate shall choose the Vice-President; a quorum for the purpose shall consist of two-thirds of the whole number of Senators, and a majority of the whole number shall be necessary to a choice. But no person constitutionally ineligible to the office of President shall be eligible to that of Vice-President of the United States.", nil)];
    Amendment* amendment13 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Abolition of Slavery", nil)
                                year:1865
                                link:@"http://en.wikipedia.org/wiki/Thirteenth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"Neither slavery nor involuntary servitude, except as a punishment for crime whereof the party shall have been duly convicted, shall exist within the United States, or any place subject to their jurisdiction.", nil)],
            [Section sectionWithText:NSLocalizedString(@"Congress shall have power to enforce this article by appropriate legislation.", nil)], nil]];
    Amendment* amendment14 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Equal Protection", nil)
                                year:1868
                                link:@"http://en.wikipedia.org/wiki/Fourteenth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"All persons born or naturalized in the United States, and subject to the jurisdiction thereof, are citizens of the United States and of the state wherein they reside. No state shall make or enforce any law which shall abridge the privileges or immunities of citizens of the United States; nor shall any state deprive any person of life, liberty, or property, without due process of law; nor deny to any person within its jurisdiction the equal protection of the laws.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"Representatives shall be apportioned among the several states according to their respective numbers, counting the whole number of persons in each state, excluding Indians not taxed. But when the right to vote at any election for the choice of electors for President and Vice President of the United States, Representatives in Congress, the executive and judicial officers of a state, or the members of the legislature thereof, is denied to any of the male inhabitants of such state, being twenty-one years of age, and citizens of the United States, or in any way abridged, except for participation in rebellion, or other crime, the basis of representation therein shall be reduced in the proportion which the number of such male citizens shall bear to the whole number of male citizens twenty-one years of age in such state.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"No person shall be a Senator or Representative in Congress, or elector of President and Vice President, or hold any office, civil or military, under the United States, or under any state, who, having previously taken an oath, as a member of Congress, or as an officer of the United States, or as a member of any state legislature, or as an executive or judicial officer of any state, to support the Constitution of the United States, shall have engaged in insurrection or rebellion against the same, or given aid or comfort to the enemies thereof. But Congress may by a vote of two-thirds of each House, remove such disability.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"The validity of the public debt of the United States, authorized by law, including debts incurred for payment of pensions and bounties for services in suppressing insurrection or rebellion, shall not be questioned. But neither the United States nor any state shall assume or pay any debt or obligation incurred in aid of insurrection or rebellion against the United States, or any claim for the loss or emancipation of any slave; but all such debts, obligations and claims shall be held illegal and void.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"The Congress shall have power to enforce, by appropriate legislation, the provisions of this article.", nil)], nil]];
    Amendment* amendment15 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Race Rights", nil)
                                year:1870
                                link:@"http://en.wikipedia.org/wiki/Fifteenth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"The right of citizens of the United States to vote shall not be denied or abridged by the United States or by any state on account of race, color, or previous condition of servitude.", nil)],
            [Section sectionWithText:NSLocalizedString(@"The Congress shall have power to enforce this article by appropriate legislation.", nil)], nil]];
    Amendment* amendment16 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Income Tax", nil)
                                year:1913
                                link:@"http://en.wikipedia.org/wiki/Sixteenth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The Congress shall have power to lay and collect taxes on incomes, from whatever source derived, without apportionment among the several states, and without regard to any census or enumeration.", nil)];
    Amendment* amendment17 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Election of Senators", nil)
                                year:1913
                                link:@"http://en.wikipedia.org/wiki/Seventeenth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The Senate of the United States shall be composed of two Senators from each state, elected by the people thereof, for six years; and each Senator shall have one vote. The electors in each state shall have the qualifications requisite for electors of the most numerous branch of the state legislatures.\n\n"
                                                       @"When vacancies happen in the representation of any state in the Senate, the executive authority of such state shall issue writs of election to fill such vacancies: Provided, that the legislature of any state may empower the executive thereof to make temporary appointments until the people fill the vacancies by election as the legislature may direct.\n\n"
                                                       @"This amendment shall not be so construed as to affect the election or term of any Senator chosen before it becomes valid as part of the Constitution.", nil)];
    Amendment* amendment18 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Prohibition", nil)
                                year:1919
                                link:@"http://en.wikipedia.org/wiki/Eighteenth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"After one year from the ratification of this article the manufacture, sale, or transportation of intoxicating liquors within, the importation thereof into, or the exportation thereof from the United States and all territory subject to the jurisdiction thereof for beverage purposes is hereby prohibited.", nil)],
            [Section sectionWithText:NSLocalizedString(@"The Congress and the several states shall have concurrent power to enforce this article by appropriate legislation.", nil)],
            [Section sectionWithText:NSLocalizedString(@"This article shall be inoperative unless it shall have been ratified as an amendment to the Constitution by the legislatures of the several states, as provided in the Constitution, within seven years from the date of the submission hereof to the states by the Congress.", nil)], nil]];
    Amendment* amendment19 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Women's Rights", nil)
                                year:1920
                                link:@"http://en.wikipedia.org/wiki/Nineteenth_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"The right of citizens of the United States to vote shall not be denied or abridged by the United States or by any state on account of sex.\n\n"
                                                       @"Congress shall have power to enforce this article by appropriate legislation.", nil)];
    Amendment* amendment20 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Presidential Succession", nil)
                                year:1933
                                link:@"http://en.wikipedia.org/wiki/Twentieth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"The terms of the President and Vice President shall end at noon on the 20th day of January, and the terms of Senators and Representatives at noon on the 3d day of January, of the years in which such terms would have ended if this article had not been ratified; and the terms of their successors shall then begin.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"The Congress shall assemble at least once in every year, and such meeting shall begin at noon on the 3d day of January, unless they shall by law appoint a different day.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"If, at the time fixed for the beginning of the term of the President, the President elect shall have died, the Vice President elect shall become President. If a President shall not have been chosen before the time fixed for the beginning of his term, or if the President elect shall have failed to qualify, then the Vice President elect shall act as President until a President shall have qualified; and the Congress may by law provide for the case wherein neither a President elect nor a Vice President elect shall have qualified, declaring who shall then act as President, or the manner in which one who is to act shall be selected, and such person shall act accordingly until a President or Vice President shall have qualified.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"The Congress may by law provide for the case of the death of any of the persons from whom the House of Representatives may choose a President whenever the right of choice shall have devolved upon them, and for the case of the death of any of the persons from whom the Senate may choose a Vice President whenever the right of choice shall have devolved upon them.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"Sections 1 and 2 shall take effect on the 15th day of October following the ratification of this article.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"This article shall be inoperative unless it shall have been ratified as an amendment to the Constitution by the legislatures of three-fourths of the several states within seven years from the date of its submission.", nil)], nil]];
    Amendment* amendment21 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Repeal of Prohibition", nil)
                                year:1933
                                link:@"http://en.wikipedia.org/wiki/Twenty-first_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"The eighteenth article of amendment to the Constitution of the United States is hereby repealed.", nil)],
            [Section sectionWithText:NSLocalizedString(@"The transportation or importation into any state, territory, or possession of the United States for delivery or use therein of intoxicating liquors, in violation of the laws thereof, is hereby prohibited.", nil)],
            [Section sectionWithText:NSLocalizedString(@"This article shall be inoperative unless it shall have been ratified as an amendment to the Constitution by conventions in the several states, as provided in the Constitution, within seven years from the date of the submission hereof to the states by the Congress.", nil)], nil]];
    Amendment* amendment22 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Presidential Term Limit", nil)
                                year:1951
                                link:@"http://en.wikipedia.org/wiki/Twenty-second_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"No person shall be elected to the office of the President more than twice, and no person who has held the office of President, or acted as President, for more than two years of a term to which some other person was elected President shall be elected to the office of the President more than once. But this article shall not apply to any person holding the office of President when this article was proposed by the Congress, and shall not prevent any person who may be holding the office of President, or acting as President, during the term within which this article becomes operative from holding the office of President or acting as President during the remainder of such term.", nil)],
            [Section sectionWithText:NSLocalizedString(@"This article shall be inoperative unless it shall have been ratified as an amendment to the Constitution by the legislatures of three-fourths of the several states within seven years from the date of its submission to the states by the Congress.", nil)], nil]];
    Amendment* amendment23 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"D.C. Vote", nil)
                                year:1961
                                link:@"http://en.wikipedia.org/wiki/Twenty-third_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"The District constituting the seat of government of the United States shall appoint in such manner as the Congress may direct:\n\n"
                                                                                 @"A number of electors of President and Vice President equal to the whole number of Senators and Representatives in Congress to which the District would be entitled if it were a state, but in no event more than the least populous state; they shall be in addition to those appointed by the states, but they shall be considered, for the purposes of the election of President and Vice President, to be electors appointed by a state; and they shall meet in the District and perform such duties as provided by the twelfth article of amendment.", nil)],
                                      [Section sectionWithText:NSLocalizedString(@"The Congress shall have power to enforce this article by appropriate legislation.", nil)], nil]];

    Amendment* amendment24 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Poll Tax", nil)
                                year:1964
                                link:@"http://en.wikipedia.org/wiki/Twenty-fourth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"The right of citizens of the United States to vote in any primary or other election for President or Vice President, for electors for President or Vice President, or for Senator or Representative in Congress, shall not be denied or abridged by the United States or any state by reason of failure to pay any poll tax or other tax.", nil)],
            [Section sectionWithText:NSLocalizedString(@"The Congress shall have power to enforce this article by appropriate legislation.", nil)], nil]];
    Amendment* amendment25 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Presidential Succession", nil)
                                year:1967
                                link:@"http://en.wikipedia.org/wiki/Twenty-fifth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"In case of the removal of the President from office or of his death or resignation, the Vice President shall become President.", nil)],
            [Section sectionWithText:NSLocalizedString(@"Whenever there is a vacancy in the office of the Vice President, the President shall nominate a Vice President who shall take office upon confirmation by a majority vote of both Houses of Congress.", nil)],
            [Section sectionWithText:NSLocalizedString(@"Whenever the President transmits to the President pro tempore of the Senate and the Speaker of the House of Representatives his written declaration that he is unable to discharge the powers and duties of his office, and until he transmits to them a written declaration to the contrary, such powers and duties shall be discharged by the Vice President as Acting President.", nil)],
            [Section sectionWithText:NSLocalizedString(@"Whenever the Vice President and a majority of either the principal officers of the executive departments or of such other body as Congress may by law provide, transmit to the President pro tempore of the Senate and the Speaker of the House of Representatives their written declaration that the President is unable to discharge the powers and duties of his office, the Vice President shall immediately assume the powers and duties of the office as Acting President.\n\n"
                                                                                 @"Thereafter, when the President transmits to the President pro tempore of the Senate and the Speaker of the House of Representatives his written declaration that no inability exists, he shall resume the powers and duties of his office unless the Vice President and a majority of either the principal officers of the executive department or of such other body as Congress may by law provide, transmit within four days to the President pro tempore of the Senate and the Speaker of the House of Representatives their written declaration that the President is unable to discharge the powers and duties of his office. Thereupon Congress shall decide the issue, assembling within forty-eight hours for that purpose if not in session. If the Congress, within twenty-one days after receipt of the latter written declaration, or, if Congress is not in session, within twenty-one days after Congress is required to assemble, determines by two-thirds vote of both Houses that the President is unable to discharge the powers and duties of his office, the Vice President shall continue to discharge the same as Acting President; otherwise, the President shall resume the powers and duties of his office.", nil)], nil]];
    Amendment* amendment26 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Vote at Age 18", nil)
                                year:1971
                                link:@"http://en.wikipedia.org/wiki/Twenty-sixth_Amendment_to_the_United_States_Constitution"
                            sections:[NSArray arrayWithObjects:
            [Section sectionWithText:NSLocalizedString(@"The right of citizens of the United States, who are 18 years of age or older, to vote, shall not be denied or abridged by the United States or any state on account of age.", nil)],
            [Section sectionWithText:NSLocalizedString(@"The Congress shall have the power to enforce this article by appropriate legislation.", nil)], nil]];
    Amendment* amendment27 =
    [Amendment amendmentWithSynopsis:NSLocalizedString(@"Congressional Compensation", nil)
                                year:1992
                                link:@"http://en.wikipedia.org/wiki/Twenty-seventh_Amendment_to_the_United_States_Constitution"
                                text:NSLocalizedString(@"No law, varying the compensation for the services of the Senators and Representatives, shall take effect, until an election of Representatives shall have intervened.", nil)];

    NSArray* articles = [NSArray arrayWithObjects:article1, article2, article3, article4, article5, article6, article7, nil];

    NSArray* amendments =
    [NSArray arrayWithObjects:amendment1, amendment2, amendment3, amendment4, amendment5,
     amendment6, amendment7, amendment8, amendment9, amendment10,
     amendment11, amendment12, amendment13, amendment14, amendment15,
     amendment16, amendment17, amendment18, amendment19, amendment20,
     amendment21, amendment22, amendment23, amendment24, amendment25,
     amendment26, amendment27, nil];

    MutableMultiDictionary* signers = [MutableMultiDictionary dictionary];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"George Washington", @"http://en.wikipedia.org/wiki/George_Washington"),
person(@"John Blair", @"http://en.wikipedia.org/wiki/John_Blair"),
person(@"James Madison Jr.", @"http://en.wikipedia.org/wiki/James_Madison"), nil] forKey:@"Virginia"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"John Langdon", @"http://en.wikipedia.org/wiki/John_Langdon"),
person(@"Nicholas Gilman", @"http://en.wikipedia.org/wiki/Nicholas_Gilman"), nil] forKey:@"New Hampshire"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"Nathaniel Gorham", @"http://en.wikipedia.org/wiki/Nathaniel_Gorham"),
person(@"Rufus King", @"http://en.wikipedia.org/wiki/Rufus_King"), nil] forKey:@"Massachusetts"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"William Samuel Johnson", @"http://en.wikipedia.org/wiki/William_Samuel_Johnson"),
person(@"Roger Sherman", @"http://en.wikipedia.org/wiki/Roger_Sherman"), nil] forKey:@"Connecticut"];
    [signers addObject:person(@"Alexander Hamilton", @"http://en.wikipedia.org/wiki/Alexander_Hamilton") forKey:@"New York"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"William Livingston", @"http://en.wikipedia.org/wiki/William_Livingston"),
person(@"David Brearly", @"http://en.wikipedia.org/wiki/David_Brearly"),
person(@"William Paterson", @"http://en.wikipedia.org/wiki/William_Paterson_(judge)"),
person(@"Jonathan Dayton", @"http://en.wikipedia.org/wiki/Jonathan_Dayton"), nil] forKey:@"New Jersey"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"Benjamin Franklin", @"http://en.wikipedia.org/wiki/Benjamin_franklin"),
person(@"Thomas Mifflin", @"http://en.wikipedia.org/wiki/Thomas_Mifflin"),
person(@"Robert Morris", @"http://en.wikipedia.org/wiki/Robert_Morris_(financier)"),
person(@"George Clymer", @"http://en.wikipedia.org/wiki/George_Clymer"),
person(@"Thomas FitzSimons", @"http://en.wikipedia.org/wiki/Thomas_Fitzsimons"),
person(@"Jared Ingersoll", @"http://en.wikipedia.org/wiki/Jared_Ingersoll"),
person(@"James Wilson", @"http://en.wikipedia.org/wiki/James_Wilson"),
person(@"Gouverneur Morris", @"http://en.wikipedia.org/wiki/Gouverneur_Morris"), nil] forKey:@"Pennsylvania"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"George Read", @"http://en.wikipedia.org/wiki/George_Read_(signer)"),
person(@"Gunning Bedford Jr.", @"http://en.wikipedia.org/wiki/Gunning_Bedford,_Jr."),
person(@"John Dickinson", @"http://en.wikipedia.org/wiki/John_Dickinson_(delegate)"),
person(@"Richard Bassett", @"http://en.wikipedia.org/wiki/Richard_Bassett"),
person(@"Jacob Broom", @"http://en.wikipedia.org/wiki/Jacob_Broom"), nil] forKey:@"Delaware"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"James McHenry", @"http://en.wikipedia.org/wiki/James_McHenry"),
person(@"Daniel of St. Thomas Jenifer", @"http://en.wikipedia.org/wiki/Daniel_of_St._Thomas_Jenifer"),
person(@"Daniel Carroll", @"http://en.wikipedia.org/wiki/Daniel_Carroll"), nil] forKey:@"Maryland"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"William Blount", @"http://en.wikipedia.org/wiki/William_Blount"),
person(@"Richard Dobbs Spaight", @"http://en.wikipedia.org/wiki/Richard_Dobbs_Spaight"),
person(@"Hugh Williamson", @"http://en.wikipedia.org/wiki/Hugh_Williamson"), nil] forKey:@"North Carolina"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"John Rutledge", @"http://en.wikipedia.org/wiki/John_Rutledge"),
person(@"Charles Cotesworth Pinckney", @"http://en.wikipedia.org/wiki/Charles_Cotesworth_Pinckney"),
person(@"Charles Pinckney", @"http://en.wikipedia.org/wiki/Charles_Pinckney_(governor)"),
person(@"Pierce Butler", @"http://en.wikipedia.org/wiki/Pierce_Butler"), nil] forKey:@"South Carolina"];
    [signers addObjects:[NSArray arrayWithObjects:
person(@"William Few", @"http://en.wikipedia.org/wiki/William_Few"),
person(@"Abraham Baldwin", @"http://en.wikipedia.org/wiki/Abraham_Baldwin"), nil] forKey:@"Georgia"];

    unitedStatesConstitution =
    [[Constitution constitutionWithCountry:country
                                  preamble:NSLocalizedString(@"We the people of the United States, in order to form a more perfect union, establish justice, insure domestic tranquility, provide for the common defense, promote the general welfare, and secure the blessings of liberty to ourselves and our posterity, do ordain and establish this Constitution for the United States of America.", nil)
                                  articles:articles
                                amendments:amendments
                                conclusion:@""
                                   signers:signers] retain];
}


+ (void) initialize {
    if (self == [UnitedStatesConstitution class]) {
        [self setupUnitedStatesConstitution];
    }
}


+ (Constitution*) unitedStatesConstitution {
    return unitedStatesConstitution;
}

@end
