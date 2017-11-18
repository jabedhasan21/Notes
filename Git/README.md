## Git recover deleted file where no commit was made after the delete
+ `git config alias.unstage`

+ `git reset HEAD /directory/file_name OR /directory/.*`

+ `git checkout -- /directory/file_name OR /directory/.*`

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
 

That's It. :)
