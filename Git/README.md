# Cheat Sheet
+ To show only commits of an individual file: `git log -- <file>`

+ To show commits of the particular file with diffs for each change: `git log -p -- <file>`

+ Show the entire history of a file (including history beyond renames): `git log --follow -p -- <file>`

+ One of the more helpful options is `-p` or `--patch`, which shows the difference (the patch output) introduced in each commit. You can also limit the number of log entries displayed, such as using `-2` to show only the last two entries: `git log -p -2`

+ If you want to see some abbreviated stats for each commit, you can use the --stat option: `git log --stat`. How many files were changed, and how many lines in those files were added and removed. It also puts a summary of the information at the end.

+ The `oneline` option prints each commit on a single line, which is useful if you’re looking at a lot of commits:`git log --pretty=oneline`

+ The most interesting option is `format`, which allows you to specify your own log output format: `git log --pretty=format:"%h -%an, %ar: %s"`
 Out Put: `c4f106c -Jabed Bangali, 3 hours ago: :sparkles: New Site Notification Account`

+ [Git-Basics-Viewing-the-Commit-History](https://git-scm.com/book/en/v2/Git-Basics-Viewing-the-Commit-History)

## Git recover deleted file where no commit was made after the delete
+ `git config alias.unstage`

+ `git reset HEAD /directory/file_name OR /directory/.*`

+ `git checkout -- /directory/file_name OR /directory/.*`

# Signing commits with GPG
+ [github](https://help.github.com/articles/signing-commits-with-gpg/)
+ [GPG Keys](https://youtu.be/xj9OiJL56pM)
## Generate GPG key
+ **Note:** Some GPG installations on Linux may require you to use `gpg2 --list-keys --keyid-format LONG` to view a list of your existing keys instead.

+ In this case you will also need to configure Git to use `gpg2` by running `git config --global gpg.program gpg2`.

+ Checking for existing GPG keys:
 - `gpg --list-keys --keyid-format LONG`
 - `gpg --list-secret-keys --keyid-format LONG`

+ To generate a GPG new key pair: `gpg2 --gen-key`

+ From the list of GPG keys, copy the GPG key ID you'd like to use. In this example, the GPG key ID is `365F613EF4097A0A`: inside the `sec`

  ```
  $ gpg2 --list-secret-key --keyid-format LONG
  /Users/jabed/.gnupg/pubring.kbx
  -------------------------------
  sec   rsa2048/365F613EF4097A0A 2017-11-18 [SC] [expires: 2019-11-18]
        1E9C3EBB9B79739C882BD8D1365F613EF4097A0A
  uid                 [ultimate] Jabed Bangali <jabedhasan21@yahoo.com>
  ssb   rsa2048/0CD2B44C210EE4F5 2017-11-18 [E] [expires: 2019-11-18]
  ```

+ To Prints the GPG key ID, in ASCII armor format: `gpg --armor --export 365F613EF4097A0A`

+ Now copy the whole output including `-----BEGIN PGP PUBLIC KEY BLOCK-----` text and add this Key in your github account.

+ To set your GPG signing key in Git:
 `$ git config --global user.signingkey 365F613EF4097A0A`

+ If you aren't using the GPG suite, paste the text below to add the GPG key to your bash profile: `echo 'export GPG_TTY=$(tty)' >> ~/.bash_profile`

+ Signing commits using GPG: `$ git commit -S -m your commit message`

+ After you create your commit, provide the passphrase you set up when you generated your GPG key.

That's It. :)

# References
