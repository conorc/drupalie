-- SUMMARY --

The Pullquote module duplicates marked-up node body text as a CSS formatted
pullquote, using according to a technique described at: http://css-tricks.com/better-pull-quotes/

For a full description visit the project page:
* http://drupal.org/project/pullquote

Bug reports, feature suggestions and latest developments:
* http://drupal.org/project/issues/pullquote

-- REQUIREMENTS --

None.

-- INSTALLATION --

1. Install and activate the module as normal, see http://drupal.org/node/895232 for further information.
2. Active Text Format /admin/config/content/formats that allows <span> html tags.
3. Optionally, activate core Help module at /admin/modules.

-- USE --

Surround any text to be duplicated as a pull quote with a span that has the class 'pullquote'.
For example: <span class="pullquote">this is a test</span>

To display on the left of the body text instead, use the class 'pullquote-left'.
For example: <span class="pullquote pullquote-left">this is a left test</span>

-- BUEDITOR INTEGRATION --

If you have not customised the default options' go to /admin/settings/bueditor/import and import the file bueditor/bueditor.txt that is included with this module.

If you have already customised BUEditor, go to /admin/settings/bueditor and then click edit for your chosen editor file, then add ...
* Title:"Pullquote"
* Content:"<span class="pullquote">%TEXT%</span>"

-- CONTACT --

Current maintainers:
* Stuckagain - http://drupal.org/user/196722
* lliss - http://drupal.org/user/724750
* callison - http://drupal.org/user/49429

Contributors:
* Sun - http://drupal.org/user/54136
* Jun Matsushita (jun) - http://drupal.org/user/49184
